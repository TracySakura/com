#include "infoitem.h"
using namespace std;
unordered_map<string, string> InfoItem::weightValueMap = {};
QString InfoItem::name() const{
    return m_name;
}
QString InfoItem::values() const{
    return m_values;
}
QString InfoItem::type() const{
    return m_type;
}
int InfoItem::appendValues(weight_node_t* weight, size_t d, ostringstream& v, int dataInd){//TODO: what if dataInd is larger
    if(d<weight->p_t->num_dims){
        v << string(4*d,' ');
        v << "[\n";
        for(int i=0;i<weight->p_t->dim_value_v[d];i++){
            if(d==weight->p_t->num_dims-1){
                v << string(4*d+4,' ');
                if(weight->data_type==TensorProto_DataType_FLOAT){//add more type
                    v<<weight->p_t->data_float->at(dataInd);
                }else if(weight->data_type==TensorProto_DataType_INT32){
                     v<<weight->p_t->data_int32->at(dataInd);
                }else if(weight->data_type==TensorProto_DataType_INT64){
                    v<<weight->p_t->data_int64->at(dataInd);
                }else if(weight->data_type==TensorProto_DataType_DOUBLE){
                    v<<weight->p_t->data_double->at(dataInd);
                }else if(weight->data_type==TensorProto_DataType_UINT64){
                    v<<weight->p_t->data_uint64->at(dataInd);
                }
                dataInd++;
            }else{
                dataInd = appendValues(weight,d+1,v,dataInd);
            }
            if (i != weight->p_t->dim_value_v[d] - 1)
                v <<",";
            v <<"\n";
        }
        v << string(4*d,' ');
        v << "]";
    }
    return dataInd;
}
