#ifndef ONNX_PB_H
#define ONNX_PB_H
enum TensorProto_DataType {
  TensorProto_DataType_UNDEFINED = 0,
  TensorProto_DataType_FLOAT = 1,
  TensorProto_DataType_UINT8 = 2,
  TensorProto_DataType_INT8 = 3,
  TensorProto_DataType_UINT16 = 4,
  TensorProto_DataType_INT16 = 5,
  TensorProto_DataType_INT32 = 6,
  TensorProto_DataType_INT64 = 7,
  TensorProto_DataType_STRING = 8,
  TensorProto_DataType_BOOL = 9,
  TensorProto_DataType_FLOAT16 = 10,
  TensorProto_DataType_DOUBLE = 11,
  TensorProto_DataType_UINT32 = 12,
  TensorProto_DataType_UINT64 = 13,
  TensorProto_DataType_COMPLEX64 = 14,
  TensorProto_DataType_COMPLEX128 = 15
};
enum AttributeProto_AttributeType {
  AttributeProto_AttributeType_UNDEFINED = 0,
  AttributeProto_AttributeType_FLOAT = 1,
  AttributeProto_AttributeType_INT = 2,
  AttributeProto_AttributeType_STRING = 3,
  AttributeProto_AttributeType_TENSOR = 4,
  AttributeProto_AttributeType_GRAPH = 5,
  AttributeProto_AttributeType_FLOATS = 6,
  AttributeProto_AttributeType_INTS = 7,
  AttributeProto_AttributeType_STRINGS = 8,
  AttributeProto_AttributeType_TENSORS = 9,
  AttributeProto_AttributeType_GRAPHS = 10
};
class AttributeProto{
public:
    typedef AttributeProto_AttributeType AttributeType;
    static const AttributeType UNDEFINED =
      AttributeProto_AttributeType_UNDEFINED;
    static const AttributeType FLOAT =
      AttributeProto_AttributeType_FLOAT;
    static const AttributeType INT =
      AttributeProto_AttributeType_INT;
    static const AttributeType STRING =
      AttributeProto_AttributeType_STRING;
    static const AttributeType TENSOR =
      AttributeProto_AttributeType_TENSOR;
    static const AttributeType GRAPH =
      AttributeProto_AttributeType_GRAPH;
    static const AttributeType FLOATS =
      AttributeProto_AttributeType_FLOATS;
    static const AttributeType INTS =
      AttributeProto_AttributeType_INTS;
    static const AttributeType STRINGS =
      AttributeProto_AttributeType_STRINGS;
    static const AttributeType TENSORS =
      AttributeProto_AttributeType_TENSORS;
    static const AttributeType GRAPHS =
      AttributeProto_AttributeType_GRAPHS;
};
#endif // ONNX_PB_H
