#ifndef KNERON_SDK_P_H
#define KNERON_SDK_P_H
#include "kneron_sdk_internal.h"
using namespace kneron_sdk;
namespace kneron_sdk
{
  class CNN_P
  {
  public:
      value_info_proto_t *p_input;
      value_info_proto_t *p_output;
      op_node_t* p_start_node;
      CNN_P();
  private:
      int addPath(vector<string> &names, op_node_t* parent, op_node_t* child, int count);
  };
}
#endif // KNERON_SDK_P_H
