#ifndef GRAPHCREATOR_H
#define GRAPHCREATOR_H
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QObject>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QuickQanava.h>
#include "../cpp/cpp_sample.h"
#include "infoitem.h"
using namespace std;
static const unordered_map<string, QColor> opColorMap = {//same as what in the qml
    {"Conv",QColor("#b254fb")},
    {"Constant",QColor("#d9bca5")},
    {"BatchNormalization",QColor("#c0a5d9")},
    {"Relu",QColor("#9395db")},
    {"Reshape",QColor("#008080")},
    {"Add",QColor("#deeda8")},
    {"AveragePool",QColor("#76cf98")},
    {"MaxPool",QColor("#a8edc3")}
};
class GraphCreator : public QObject
{
    Q_OBJECT
public:
    GraphCreator(QObject *parent = 0):QObject(parent){}
    Q_INVOKABLE void createGraph(CustomGraph* g, QString path, QQuickItem* wV);
    Q_INVOKABLE void showNodeInfo(QQuickItem* infoItem, QString name);
    Q_INVOKABLE void deleteItem(QQuickItem* item);
    Q_INVOKABLE void setWeightValue(QString weightStr);
    Q_INVOKABLE void release();
    Q_INVOKABLE void weightValueRelease();
    static QPointer<QQuickItem> weightValues;
private:
    static constexpr qreal xMid=640.;
    static constexpr qreal ySpacing=30.;
    static constexpr qreal xSpacing=30.;
    vector<QObject*> infoitems;//delete when component destroyed
    unordered_map<string,intermediate_node_t*> intersMap;
    unordered_map<string,op_node_t*> nodesMap;
    void createNode(qan::Node* node, op_node_t* nodeInfo);
    void createInputNode(qan::Node* inputNode, string name, qreal xMid, qreal y);
    vector<qreal> createNodesInPath(QPointer<CustomGraph> graph, op_node_t* nodeInfo, qreal pos, qreal y, qreal left, qreal right, vector<qan::Node*> &endNodes, qan::Node* prevNode);
};

#endif // GRAPHCREATOR_H
