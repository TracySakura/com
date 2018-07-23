#include "graphcreator.h"
#include <fstream>
QPointer<QQuickItem> GraphCreator::weightValues = nullptr;
/*
 * add input and output into the customnode
 */
void GraphCreator::createInputNode(qan::Node* inputNode, string name, qreal xMid, qreal y){
    inputNode->getItem()->setProperty("nameStr",QString::fromStdString(name));
    inputNode->getItem()->setX(xMid-(inputNode->getItem()->width()/2));
    inputNode->getItem()->setY(y);
}
/*
 * add inputs and attribute info into the customnode
 */
void GraphCreator::createNode(qan::Node* node, op_node_t* nodeInfo){
    node->getItem()->setObjectName(QString::fromStdString(nodeInfo->name));
    QQmlEngine* engine = QtQml::qmlEngine( this );
    node->setLabel(QString(QChar(nodeInfo->type.at(0))));
    QQuickItem *background = node->getItem()->findChild<QQuickItem*>("background");
    if(opColorMap.find(nodeInfo->type)==opColorMap.end()){
        background->setProperty("color",QColor("#6f9fab"));
        node->getItem()->setProperty("styleBackColor",QColor("#6f9fab"));
    }else{
        background->setProperty("color",opColorMap.at(nodeInfo->type));
        node->getItem()->setProperty("styleBackColor",opColorMap.at(nodeInfo->type));
    }
    //map the name and op_node
    nodesMap.insert({nodeInfo->name,nodeInfo});
    for(auto it = nodeInfo->inputIntermediateNodePointerList.begin();it!=nodeInfo->inputIntermediateNodePointerList.end();++it){
        intersMap.insert({(*it)->name,(*it)});
    }
}
/*
 * create all nodes in the path, return the updated y , left and right
 * pos<0:left side;pos>0 right side;pos=0 middle
 */
vector<qreal> GraphCreator::createNodesInPath(QPointer<CustomGraph> graph, op_node_t* nodeInfo, qreal pos, qreal y, qreal left, qreal right, vector<qan::Node*> &endNodes, qan::Node* prevNode){
    vector<qan::Node*> nodes;
    qreal maxWid = 0;
    while(nodeInfo->prev_num==1){
        nodes.push_back(graph->insertCustomNode());
        createNode(nodes.back(),nodeInfo);
        if(nodes.back()->getItem()->width()>maxWid)
            maxWid = nodes.back()->getItem()->width();
        nodeInfo = nodeInfo->nextOpNodePointerList.front();
    }
    endNodes.push_back(nodes.back());
    qreal pathMid=xMid;
    if(pos<0){
        pathMid = left-maxWid/2;
        left -= (maxWid+xSpacing);
    }else if(pos>0){
        pathMid = right+maxWid/2;
        right += (maxWid+xSpacing);
    }else{
        left -= maxWid/2;
        right += maxWid/2;
    }
    for(size_t i=0;i<nodes.size();i++){
        nodes[i]->getItem()->setX(pathMid - nodes[i]->getItem()->width()/2);
        nodes[i]->getItem()->setY(y);
        y += nodes[i]->getItem()->height()+ySpacing;
        if(i>0)
            graph->insertCustomEdge(nodes[i-1],nodes[i]);
        else
            graph->insertCustomEdge(prevNode, nodes[0]);
    }
    vector<qreal> res;
    res.push_back(y);
    res.push_back(left);
    res.push_back(right);
    return res;
}
/*
 *create the graph base on the onnx model
 */
void GraphCreator::createGraph(CustomGraph* g, QString path, QQuickItem* wV){
    fstream input_file(path.toStdString(), ios::in | ios::binary);
    if(!input_file){
        int ddd = 0;
    }
    QPointer<CustomGraph> graph = qobject_cast<CustomGraph*>(g);
    string pathStr = path.toStdString();
    vector<char> pa_chars(pathStr.begin(),pathStr.end());
    initCNNModel(&pa_chars[0]);
    op_node_t* startNode = getStartNode();
    if (graph&&startNode) {
        //add output node to intersMap
        intersMap.insert({getOutputNodeInfo()->name,new intermediate_node(*getOutputNodeInfo())});
        qreal y{30.};
        //get the weight item
        weightValues = qobject_cast<QQuickItem*>(wV);
        //add input node
        qan::Node* infoNode = graph->insertInputNode();
        createInputNode(infoNode,getInputNodeInfo()->name,xMid, y);
        y += infoNode->getItem()->height()+ySpacing;
        vector<qan::Node*> endNodes;
        endNodes.push_back(infoNode);
        op_node_t* currentNode = startNode;
        while (currentNode){
            qan::Node* node = graph->insertCustomNode();
            createNode(node,currentNode);
            node->getItem()->setX(xMid-(node->getItem()->width()/2));
            node->getItem()->setY(y);
            //add edges
            while(!endNodes.empty()){
                graph->insertEdge(endNodes.back(),node);
                endNodes.pop_back();
            }
            y += node->getItem()->height()+ySpacing;
            if(currentNode->next_num==0){
                endNodes.push_back(node);
                break;
            }else if(currentNode->next_num>1){
                qreal right = xMid+xSpacing;
                qreal left = xMid-xSpacing;
                qreal maxY = y;
                //if there is skip
                bool skip = false;
                for(auto it=currentNode->nextOpNodePointerList.begin();it!=currentNode->nextOpNodePointerList.end();++it){
                    if((*it)->prev_num>1){
                        skip = true;
                        break;
                    }
                }
                for(int i=0;i<currentNode->next_num;i++){
                    vector<qreal> pos;
                    if(currentNode->nextOpNodePointerList[i]->prev_num>1){//skip
                        endNodes.push_back(node);
                        continue;
                    }else if(i==0&&(!skip)&&currentNode->next_num%2==1){//no skip and ood path
                        pos = createNodesInPath(graph, currentNode->nextOpNodePointerList[i],0,y,left,right,endNodes,node);
                    }else if(i%2==0){
                        pos = createNodesInPath(graph, currentNode->nextOpNodePointerList[i],-1,y,left,right,endNodes,node);
                    }else{
                        pos = createNodesInPath(graph, currentNode->nextOpNodePointerList[i],1,y,left,right,endNodes, node);
                    }
                    if(pos[0]>maxY)
                        maxY = pos[0];
                    left = pos[1];
                    right = pos[2];
                }
                currentNode = currentNode->nextOpNodePointerList.front();
                while(currentNode->prev_num==1){
                    currentNode = currentNode->nextOpNodePointerList.front();
                }
                y = maxY;
            }else{
                currentNode=currentNode->nextOpNodePointerList.front();
                endNodes.push_back(node);
            }
        }
        //add output node
        infoNode = graph->insertInputNode();
        createInputNode(infoNode,getOutputNodeInfo()->name,xMid, y);
        graph->insertEdge(endNodes.back(),infoNode);
    }
}
/*
 * show detail of the node
 */
void GraphCreator::showNodeInfo(QQuickItem* infoItem, QString name){
    //release former infoitems
    if(nodesMap.find(name.toStdString())==nodesMap.end()){
        return;//TODO: graph info
    }
    op_node_t* node = nodesMap[name.toStdString()];//get op_node
    QQmlEngine* engine = QtQml::qmlEngine( this );
    QQmlContext *ctxt = engine->rootContext();  
    //delete the former infoitems
    QList<QObject*> emptyList;
    ctxt->setContextProperty("attrModel",QVariant::fromValue(emptyList));
    ctxt->setContextProperty("inputModel",QVariant::fromValue(emptyList));
    ctxt->setContextProperty("weightModel",QVariant::fromValue(emptyList));
    ctxt->setContextProperty("outputModel",QVariant::fromValue(emptyList));
    while(!infoitems.empty()){
        delete infoitems.back();
        infoitems.pop_back();
    }
    //get all component needed
    QPointer<QQuickItem> mainLayout = qobject_cast<QQuickItem*>(infoItem->findChild<QQuickItem*>("mainLayout"));
    QPointer<QQuickItem> typeStr = qobject_cast<QQuickItem*>(mainLayout->findChild<QQuickItem*>("typeStr"));
    typeStr->setProperty("text",QString::fromStdString(node->type));
    QPointer<QQuickItem> nodeName = qobject_cast<QQuickItem*>(mainLayout->findChild<QQuickItem*>("nodeName"));
    nodeName->setProperty("text",QString::fromStdString(node->name));
    //add attribute
    if(node->attribute_num>0){
        //add title
        QQmlComponent component1(engine, QUrl(QStringLiteral("qrc:/InfoTitle.qml")));
        QQuickItem *title = qobject_cast<QQuickItem*>(component1.create());
        QQmlEngine::setObjectOwnership(title, QQmlEngine::CppOwnership);
        title->setParent(engine);
        title->setParentItem(mainLayout);
        title->setProperty("text","Attribute");
        //add attributes
        QQmlComponent component2(engine, QUrl(QStringLiteral("qrc:/InfoAttrListView.qml")));
        QQuickItem *attrs = qobject_cast<QQuickItem*>(component2.create());
        QQmlEngine::setObjectOwnership(attrs, QQmlEngine::CppOwnership);
        attrs->setParent(engine);
        attrs->setParentItem(mainLayout);
        QList<QObject*> attrList;
        if(node->attrFloatList.size()>0){
            for(auto it=node->attrFloatList.begin();it!=node->attrFloatList.end();++it){
                attrList.append(new InfoItem(&(*it)));
            }
        }
        if(node->attrIntList.size()>0){
            for(auto it=node->attrIntList.begin();it!=node->attrIntList.end();++it){
                attrList.append(new InfoItem(&(*it)));
            }
        }
        if(node->attrStringList.size()>0){
            for(auto it=node->attrStringList.begin();it!=node->attrStringList.end();++it){
                attrList.append(new InfoItem(&(*it)));
            }
        }
        ctxt->setContextProperty("attrModel",QVariant::fromValue(attrList));
        //store all pointers
        for(auto it = attrList.begin();it!=attrList.end();++it){
            infoitems.push_back(*it);
        }
    }
    //add inputs
    if(node->input_intermediate_num>0){
        //add title
        QQmlComponent inputComponent(engine, QUrl(QStringLiteral("qrc:/InfoTitle.qml")));
        QQuickItem *inputTitle = qobject_cast<QQuickItem*>(inputComponent.create());
        QQmlEngine::setObjectOwnership(inputTitle, QQmlEngine::CppOwnership);
        inputTitle->setParent(engine);
        inputTitle->setParentItem(mainLayout);
        inputTitle->setProperty("text","Inputs");
        //add inputs
        QQmlComponent component2(engine, QUrl(QStringLiteral("qrc:/InfoInputListView.qml")));
        QQuickItem *inputs = qobject_cast<QQuickItem*>(component2.create());
        QQmlEngine::setObjectOwnership(inputs, QQmlEngine::CppOwnership);
        inputs->setParent(engine);
        inputs->setParentItem(mainLayout);
        QList<QObject*> interList;
        for(int i=0;i<node->input_intermediate_num;i++){
            char letter = 'A'+i;
            interList.append(new InfoItem(node->inputIntermediateNodePointerList[i],string(1,letter)));
        }
        //store all pointers
        for(auto it = interList.begin();it!=interList.end();++it){
            infoitems.push_back(*it);
        }
        ctxt->setContextProperty("inputModel",QVariant::fromValue(interList));
    }
    //add weights
    if(node->input_weight_num>0){
        //add title
        QQmlComponent component1(engine, QUrl(QStringLiteral("qrc:/InfoTitle.qml")));
        QQuickItem *title = qobject_cast<QQuickItem*>(component1.create());
        QQmlEngine::setObjectOwnership(title, QQmlEngine::CppOwnership);
        title->setParent(engine);
        title->setParentItem(mainLayout);
        title->setProperty("text","Weights");
        //add weights
        QQmlComponent component2(engine, QUrl(QStringLiteral("qrc:/InfoWeightListView.qml")));
        QQuickItem *weights = qobject_cast<QQuickItem*>(component2.create());
        QQmlEngine::setObjectOwnership(weights, QQmlEngine::CppOwnership);
        weights->setParent(engine);
        weights->setParentItem(mainLayout);
        QList<QObject*> weightList;
        for(auto it = node->inputweightNodePointerlist.begin();it!=node->inputweightNodePointerlist.end();++it){
            weightList.append(new InfoItem(*it));
        }
        //store all pointers
        for(auto it = weightList.begin();it!=weightList.end();++it){
            infoitems.push_back(*it);
        }
        ctxt->setContextProperty("weightModel",QVariant::fromValue(weightList));
    }
    //add outputs
    if(node->output_num>0){
        QQmlComponent outputComponent(engine, QUrl(QStringLiteral("qrc:/InfoTitle.qml")));
        QQuickItem *outputTitle = qobject_cast<QQuickItem*>(outputComponent.create());
        QQmlEngine::setObjectOwnership(outputTitle, QQmlEngine::CppOwnership);
        outputTitle->setParent(engine);
        outputTitle->setParentItem(mainLayout);
        outputTitle->setProperty("text","Outputs");
        //add outputs
        QQmlComponent component2(engine, QUrl(QStringLiteral("qrc:/InfoOutputListView.qml")));
        QQuickItem *outputs = qobject_cast<QQuickItem*>(component2.create());
        QQmlEngine::setObjectOwnership(outputs, QQmlEngine::CppOwnership);
        outputs->setParent(engine);
        outputs->setParentItem(mainLayout);
        QList<QObject*> interList;
        for(auto it=node->outputNodeNameList.begin();it!=node->outputNodeNameList.end();++it){
            interList.append(new InfoItem(intersMap.at(*it),"Y"));
        }
        ctxt->setContextProperty("outputModel",QVariant::fromValue(interList));
        //store all pointers
        for(auto it = interList.begin();it!=interList.end();++it){
            infoitems.push_back(*it);
        }
    }
    infoItem->setVisible(true);
}
/*
 * set and show the weight value
 */
void GraphCreator::setWeightValue(QString weightStr){
    QQmlEngine* engine = QtQml::qmlEngine( this );
    QQmlContext *ctxt = engine->rootContext();
    QList<QObject*> weightValueList;
    weightValueList.append(new InfoItem(weightStr));
    infoitems.push_back(weightValueList.at(0));//delete when component destroyed
    ctxt->setContextProperty("weightValueModel",QVariant::fromValue(weightValueList));
    weightValues->setVisible(true);
}

/*
 * delete one QQuickItem
 */
void GraphCreator::deleteItem(QQuickItem* item){
    item->deleteLater();
}
/*
 * delete all pointers when close the window
 */
void GraphCreator::release(){
    weightValues->setVisible(false);
    QQmlEngine* engine = QtQml::qmlEngine( this );
    QQmlContext *ctxt = engine->rootContext();
    QList<QObject*> emptyList;
    ctxt->setContextProperty("attrModel",QVariant::fromValue(emptyList));
    ctxt->setContextProperty("inputModel",QVariant::fromValue(emptyList));
    ctxt->setContextProperty("weightModel",QVariant::fromValue(emptyList));
    ctxt->setContextProperty("outputModel",QVariant::fromValue(emptyList));
    for(auto it = infoitems.begin();it!=infoitems.end();++it){
        delete (*it);
    }
    if(intersMap.find(getOutputNodeInfo()->name)!=intersMap.end())
        delete intersMap.at(getOutputNodeInfo()->name);
}
/*
 * release the infoitem when click on another node
 */
void GraphCreator::weightValueRelease(){
    weightValues->setVisible(false);
    QQmlEngine* engine = QtQml::qmlEngine( this );
    QQmlContext *ctxt = engine->rootContext();
    QList<QObject*> emptyList;
    ctxt->setContextProperty("weightValueModel",QVariant::fromValue(emptyList));
    for(auto it = infoitems.begin();it!=infoitems.end();++it){
        delete (*it);
    }
}
/*
 * get the color of the op-color map
 */
QColor GraphCreator::getOpColor(QString opStr){
    if(opColorMap.find(opStr.toStdString())==opColorMap.end()){
        return QColor("#6f9fab");
    }else{
        return opColorMap.at(opStr.toStdString());
    }
}
