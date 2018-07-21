#include "kneron_internal_api.h"

using namespace std;
using namespace kneron_sdk;
CNN_P *p_CNN;
int initCNNModel(const char* onnx_model_file)
{
  p_CNN =  new CNN_P();
  return 1;
}
value_info_proto_t* getInputNodeInfo()
{
    return p_CNN->p_input;
}

value_info_proto_t* getOutputNodeInfo()
{
    return p_CNN->p_output;
}

op_node_t* getStartNode()
{
    return p_CNN->p_start_node;
}
