#ifndef KNERON_INTERNAL_API_H
#define KNERON_INTERNAL_API_H
#include "kneron_sdk_p.h"
using namespace std;
using namespace kneron_sdk;
int initCNNModel(const char* onnx_model_file);
kneron_sdk::value_info_proto_t* getInputNodeInfo();
kneron_sdk::value_info_proto_t* getOutputNodeInfo();
kneron_sdk::op_node_t* getStartNode();

#endif // KNERON_INTERNAL_API_H
