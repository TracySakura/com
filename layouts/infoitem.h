#ifndef INFOITEM_H
#define INFOITEM_H

#include<QObject>
#include <unordered_map>
#include "kneron_internal_api.h"
using namespace std;
struct EnumClassHash//calculate hash for enum class
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};
static const unordered_map<TensorProto_DataType, string, EnumClassHash> tensorTypes= {
        {TensorProto_DataType_BOOL, "bool" },
        {TensorProto_DataType_COMPLEX128,"complex128" },
        {TensorProto_DataType_COMPLEX64, "complex64" },
        {TensorProto_DataType_DOUBLE, "double" },
        {TensorProto_DataType_FLOAT, "float" },
        {TensorProto_DataType_FLOAT16, "float16" },
        {TensorProto_DataType_INT16, "int16" },
        {TensorProto_DataType_INT32, "int32" },
        {TensorProto_DataType_INT64, "int64" },
        {TensorProto_DataType_INT8, "int8" },
        {TensorProto_DataType_STRING,"string" },
        {TensorProto_DataType_UINT16,"unit16" },
        {TensorProto_DataType_UINT32,"unit32" },
        {TensorProto_DataType_UINT64,"unit64" },
        {TensorProto_DataType_UINT8,"unit8" },
        {TensorProto_DataType_UNDEFINED,"undifined" }
};
static const unordered_map<TensorProto_DataType, double_t, EnumClassHash> typeSize= {
        {TensorProto_DataType_BOOL, 1.},
        {TensorProto_DataType_COMPLEX128,  16.},
        {TensorProto_DataType_COMPLEX64, 8.},
        {TensorProto_DataType_DOUBLE, 8. },
        {TensorProto_DataType_FLOAT, 4. },
        {TensorProto_DataType_FLOAT16, 2. },
        {TensorProto_DataType_INT16, 2. },
        {TensorProto_DataType_INT32, 4. },
        {TensorProto_DataType_INT64, 8.},
        {TensorProto_DataType_INT8, 1. },
        {TensorProto_DataType_STRING, 16. },//fixed number(not exact size)
        {TensorProto_DataType_UINT16, 2. },
        {TensorProto_DataType_UINT32, 4. },
        {TensorProto_DataType_UINT64, 8. },
        {TensorProto_DataType_UINT8, 1. },
        {TensorProto_DataType_UNDEFINED, 16. }//fixed number(not exact size)
};
class InfoItem:public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString values READ values NOTIFY valuesChanged)
    Q_PROPERTY(QString type READ type NOTIFY typeChanged)
public:
    static unordered_map<string, string> weightValueMap;
    InfoItem(QString v,QObject *parent = 0):QObject(parent){//for weight value
        m_values = QString::fromStdString(weightValueMap.at(v.toStdString()));
    }
    InfoItem(op_node_attr* attr, QObject *parent = 0):QObject(parent){//attribute list model
        m_name = QString::fromStdString(attr->name);
        ostringstream value;
        if(attr->data_string.size()>0){
            for(auto it=attr->data_string.begin();it!=attr->data_string.end();++it){
                if(it!=attr->data_string.begin())
                    value<<", ";
                value<<*it;
            }
            m_type = "string[]";
        }else if(attr->data_float.size()>0){
            for(auto it=attr->data_float.begin();it!=attr->data_float.end();++it){
                if(it!=attr->data_float.begin())
                    value<<", ";
                value<<*it;
            }
            m_type = "float[]";
        }else if(attr->data_int64.size()>0){
            for(auto it=attr->data_int64.begin();it!=attr->data_int64.end();++it){
                if(it!=attr->data_int64.begin())
                    value<<", ";
                value<<*it;
            }
            m_type = "int64[]";
        }
        m_values = QString::fromStdString(value.str());
    }
    InfoItem(intermediate_node_t* input, string index, QObject *parent = 0):QObject(parent){//intermediate node list model
        m_name = QString::fromStdString(index + " : "+input->name);
        ostringstream t;//type string
        t << tensorTypes.at(input->data_type);
        double_t size = 0.;//calculate the size required
        if(input->p_info->num_dims>0){
            size = 1.;
            t<<" [ ";
            for(auto it = input->p_info->dim_value.begin();it!=input->p_info->dim_value.end();++it){
                if(it!=input->p_info->dim_value.begin())
                    t << ", ";
                t<<*it;
                size *= (*it);
            }
            t<<" ]";
            size /= 1024;
            size *= typeSize.at(input->data_type);
        }
        ostringstream v;//size
        v<<"size: ";
        v<<size;
        v<<" KB";
        m_type = QString::fromStdString(t.str());
        m_values = QString::fromStdString(v.str());
    }
    //TODO: map weight name
    InfoItem(weight_node_t* weight, QObject *parent = 0):QObject(parent){//weight node list model
        m_name = QString::fromStdString(weight->name);
        ostringstream t;//type string
        t << tensorTypes.at(weight->data_type);
        if(weight->p_t->num_dims>0){
            t<<" [ ";
            for(auto it = weight->p_t->dim_value_v.begin();it!=weight->p_t->dim_value_v.end();++it){
                if(it != weight->p_t->dim_value_v.begin())
                    t<<",";
                t<<*it;
            }
            t<<" ]";
        }
        m_type = QString::fromStdString(t.str());
        ostringstream v;
        if(weightValueMap.find(weight->name)==weightValueMap.end()){//convert the value list into string and store it in the weightValueMap
            appendValues(weight,0,v,0);
            weightValueMap.insert({weight->name,v.str()});
        }
    }
    QString name() const;
    QString values() const;
    QString type() const;
private:
    QString m_name;
    QString m_values;
    QString m_type;
    int appendValues(weight_node_t* weight, size_t d, ostringstream& v, int dataInd);
signals:
    void nameChanged(QString name);
    void valuesChanged(QString data);
    void typeChanged(QString type);
};

#endif // INFOITEM_H
