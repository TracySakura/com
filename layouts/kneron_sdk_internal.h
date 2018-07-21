#include <list>
#include <vector>
#include <complex>
//#include <type_traits>
//#include <stdexcept>
#include "onnx.pb.h"
//#include "half.hpp"
//#include "../../../core/header/operation_node.h"

using namespace std;
//using namespace onnx;
//using half_float::half;
namespace kneron_sdk
{
//  typedef
//  struct tensor_shape_proto_dimension
//  {
//    int index;
//    size_t ByteSizeLong;
		
//    bool has_denotation;
//    string denotation;
			 
//    bool has_dim_value;
//    google::protobuf::int64 dim_value;
		
//    bool has_dim_param;
//    string dim_param;
			
//    tensor_shape_proto_dimension(TensorShapeProto_Dimension &Dimension)
//    {
//      ByteSizeLong = Dimension.ByteSizeLong();
			
//      if (true == (has_denotation = Dimension.has_denotation())){
//        denotation = Dimension.denotation();
//      }
//      if (true == (has_dim_value = Dimension.has_dim_value())){
//        dim_value = Dimension.dim_value();
//      }
//      if (true == (has_dim_param = Dimension.has_dim_param())) {
//        dim_param = Dimension.dim_param();
//      }
//    }
//  } tensor_shape_proto_dimension_t;
 
  typedef
  struct tensor_shape_proto
  {
//	size_t ByteSizeLong;
    int dim_num;
    std::vector<int64_t>  dim_l;
	
//	tensor_shape_proto(onnx::TensorShapeProto &Tensorshape)
//	{
//	  ByteSizeLong = Tensorshape.ByteSizeLong();

//      if (0 < (dim_num = Tensorshape.dim_size())) {
//		::google::protobuf::RepeatedPtrField< ::onnx::TensorShapeProto_Dimension > dim = Tensorshape.dim();
//		for (auto it = dim.begin(); it!= dim.end(); ++it) {
//          tensor_shape_proto_dimension_t *p_dim_tmp = new tensor_shape_proto_dimension(*it);
//          dim_l.push_back(p_dim_tmp->dim_value);
//		}
//	  }
//	}
  } tensor_shape_proto_t;
	
    typedef
    struct type_proto_tensor
    {
//		size_t ByteSizeLong;
        bool has_shape;
        tensor_shape_proto_t *p_shape;
				
        bool has_elem_type;
        TensorProto_DataType elem_type;
		
//		type_proto_tensor(onnx::TypeProto_Tensor &TypeTensor )
//	{
//			ByteSizeLong = TypeTensor.ByteSizeLong();
		
//			if (true == (has_shape = TypeTensor.has_shape())) {
//				const onnx::TensorShapeProto &Tensorshape = TypeTensor.shape();
//				p_shape = new tensor_shape_proto(const_cast<onnx::TensorShapeProto&>(Tensorshape));
//		}
//		if (true == (has_elem_type = TypeTensor.has_elem_type())) {
//				elem_type = TypeTensor.elem_type();
//			}
//		}
    } type_proto_tensor_t;

    typedef
    struct type_proto
    {
//		size_t ByteSizeLong;
		 
        bool has_tensor_type;
        type_proto_tensor_t *p_type_proto_tensor;
	 
//		type_proto(TypeProto &Type)
//		{
//			if (true == (has_tensor_type = Type.has_tensor_type())) {
//				const ::onnx::TypeProto_Tensor &TypeTensor = Type.tensor_type();
//				p_type_proto_tensor = new type_proto_tensor(const_cast<onnx::TypeProto_Tensor&>(TypeTensor));
//			}
//		}
    } type_proto_t;

	typedef 
	struct value_info_proto 
	{
//		size_t ByteSizeLong;
		bool has_name; 
		string name;

//		bool has_doc_string;
//		string doc_string;
	
        bool has_type;
        type_proto_t *p_type;
		
//		value_info_proto(onnx::ValueInfoProto &ValueInfo)
//		{
//			ByteSizeLong = ValueInfo.ByteSizeLong();
		
//			if (true == (has_name = ValueInfo.has_name())) {
//				name = ValueInfo.name();
//		}
//		if (true == (has_doc_string = ValueInfo.has_doc_string())) {
//				doc_string = ValueInfo.doc_string();
//		}
//		if (true == (has_type = ValueInfo.has_type())) {
//		const ::onnx::TypeProto &Type = ValueInfo.type();
//				p_type = new type_proto(const_cast<::onnx::TypeProto &>(Type));
//			}
//		}
        value_info_proto(string n){
            has_name = true;
            name = n;
            has_type = true;
            p_type = new type_proto();
            p_type->has_tensor_type = true;
            p_type->p_type_proto_tensor = new type_proto_tensor();
            p_type->p_type_proto_tensor->has_elem_type = true;
            p_type->p_type_proto_tensor->elem_type = TensorProto_DataType_UINT32;
            p_type->p_type_proto_tensor->has_shape = true;
            p_type->p_type_proto_tensor->p_shape = new tensor_shape_proto();
            p_type->p_type_proto_tensor->p_shape->dim_l.push_back(3);
            p_type->p_type_proto_tensor->p_shape->dim_num = 1;
        }
	} value_info_proto_t;

//	typedef
//	struct tensor_proto_segment
//	{
//		size_t ByteSizeLong;
	 
//	bool has_begin;
//	::google::protobuf::int64 begin;
	
//	bool has_end;
//	::google::protobuf::int64 end;
	
//	tensor_proto_segment(TensorProto_Segment &TensorSegment)
//	{
//		ByteSizeLong = TensorSegment.ByteSizeLong();
//			has_begin = TensorSegment.has_begin();
//		has_end = TensorSegment.has_end();
//			begin = TensorSegment.begin();
//			end = TensorSegment.end();
//	}
	
//	} tensor_proto_segment_t;

//	typedef
//	struct tensor_proto
//	{
//		size_t ByteSizeLong;
		
//	int dims_num;
//		std::vector<::google::protobuf::int64> dims_v;
	
//	int float_data_size;
//	std::vector<float> float_data_v;
	
//	int int32_data_size;
//	std::vector<::google::protobuf::int32> int32_data_v;
	 
//	int string_data_size;
//	std::list<::std::string> string_data_l;
			 
//	int int64_data_size;
//	std::vector<::google::protobuf::int64> int64_data_v;
		 
//	int double_data_size;
//	std::vector<double> double_data_v;

//	int uint64_data_size;
//	std::vector<::google::protobuf::uint64 > uint64_data_v;
	
//	bool has_name;
//	string name;
	
//		bool has_raw_data;
//		string raw_data;
			
//		bool has_doc_string;
//		string doc_string;
	
//		bool has_segment;
//		tensor_proto_segment_t *p_segment;
	
//		bool has_data_type;
//		onnx::TensorProto_DataType data_type;
				
//		tensor_proto(onnx::TensorProto &Tensor)
//		{
//			ByteSizeLong = Tensor.ByteSizeLong();
//		if (0 < (dims_num = Tensor.dims_size())) {
//		 ::google::protobuf::RepeatedField< ::google::protobuf::int64 > dim = Tensor.dims();
//		 for (auto it = dim.begin(); it!= dim.end(); ++it) {
//			 dims_v.push_back(*it);
//			 }
//		};
//		if (0 < (float_data_size = Tensor.float_data_size())) {
//		::google::protobuf::RepeatedField< float >  float_datas = Tensor.float_data();
//			for (auto it = float_datas.begin(); it!= float_datas.end(); ++it) {
//			float_data_v.push_back(*it);
//				}
//		}
//		if (0 < (int32_data_size = Tensor.int32_data_size())) {
//			::google::protobuf::RepeatedField< ::google::protobuf::int32 > int32_data = Tensor.int32_data();
//			for (auto it = int32_data.begin(); it != int32_data.end(); ++it) {
//			int32_data_v.push_back(*it);
//				}
//		}
//		if (0 < (string_data_size = Tensor.string_data_size())) {
//			::google::protobuf::RepeatedPtrField< ::std::string> string_data = Tensor.string_data();
//			for (auto it = string_data.begin(); it != string_data.end(); ++it) {
//			string_data_l.push_back(*it);
//				}
//		}
//		if (0 < (int64_data_size = Tensor.int64_data_size())) {
//			::google::protobuf::RepeatedField< ::google::protobuf::int64 > int64_data = Tensor.int64_data();
//			for (auto it = int64_data.begin(); it != int64_data.end(); ++it) {
//			int64_data_v.push_back(*it);
//				}
//		}
//		if (0 < (double_data_size = Tensor.double_data_size())) {
//			::google::protobuf::RepeatedField< double >  double_data = Tensor.double_data();
//			for (auto it = double_data.begin(); it != double_data.end(); ++it) {
//			double_data_v.push_back(*it);
//				}
//		}
//		if (0 < (uint64_data_size = Tensor.uint64_data_size())) {
//			::google::protobuf::RepeatedField< ::google::protobuf::uint64 > uint64_data = Tensor.uint64_data();
//			for (auto it = uint64_data.begin(); it != uint64_data.end(); ++it) {
//			uint64_data_v.push_back(*it);
//				}
//		}
//			if (true == (has_name = Tensor.has_name())) {
//				name = Tensor.name();
//		}
//			if (true == (has_raw_data = Tensor.has_raw_data())) {
//				raw_data = Tensor.raw_data();
//		}
//		if (true == (has_doc_string = Tensor.has_doc_string())) {
//				has_doc_string = Tensor.has_doc_string();
//			}
//		if (true == (has_data_type = Tensor.has_data_type())) {
//				 data_type  = Tensor.data_type();
//			}
//		}
//	} tensor_proto_t;


//	typedef
//	struct attribute_proto  {
//		ulong index;
//		size_t ByteSizeLong;
		
//		int floats_size;
//		std::vector<float> float_l;
				
//		int ints_size;
//		std::list<::google::protobuf::int64> int_l;
		
//		int strings_num;
//		std::list<string> string_l;
			 
//		int tensors_size;
//		std::list<tensor_proto_t> tensor_l;
		
//	//  int graphs_size;
//	//  std::list<graph_proto_t> graph_l;
		
//		bool has_name;
//		string name;
		
//		bool has_s;
//		string s;
 
//		bool has_doc_string;
//		string doc_string;
		 
//		bool has_ref_attr_name;
//		string ref_attr_name;
	
//		bool has_t;
//		tensor_proto_t *p_t;
			
//	 // bool has_g;
//	 // graph_proto *p_g;
		 
//		bool has_i;
//		::google::protobuf::int64 i;
		
//		bool has_f;
//		float f;
		
//		bool has_type;
//		enum AttributeProto_AttributeType type;
		
//		attribute_proto(onnx::AttributeProto &Attribute)
//		{
//			ByteSizeLong = Attribute.ByteSizeLong();

//			if (0 < (ints_size = Attribute.ints_size())) {
//			::google::protobuf::RepeatedField< ::google::protobuf::int64 > ints = Attribute.ints();
//			for (auto it = ints.begin(); it != ints.end(); ++it) {
//					int_l.push_back(*it);
//				}
//			}
//			if (0 < (floats_size = Attribute.floats_size())) {
//			::google::protobuf::RepeatedField< float > floats = Attribute.floats();
//			for (auto it = floats.begin(); it != floats.end(); ++it) {
//					float_l.push_back(*it);
//				}
//			}
//			if (0 < (strings_num = Attribute.strings_size())) {
//			::google::protobuf::RepeatedPtrField< ::std::string> strings = Attribute.strings();
//			for (auto it = strings.begin(); it != strings.end(); ++it) {
//					string_l.push_back(*it);
//				}
//			}
//			if (0 < (tensors_size = Attribute.tensors_size())) {
//			::google::protobuf::RepeatedPtrField< ::onnx::TensorProto > tensors = Attribute.tensors();
//			for (auto it = tensors.begin(); it != tensors.end(); ++it) {
//					tensor_proto_t *p_tensor_t = new tensor_proto(*it);
//					tensor_l.push_back(*p_tensor_t);
//				}
//			}
//			if (true == (has_name = Attribute.has_name())) {
//				name = Attribute.name();
//		}
//		if (true == (has_s = Attribute.has_s())) {
//				s = Attribute.s();
//				string_l.push_back(s);
//		}
//		if (true == (has_doc_string = Attribute.has_doc_string())) {
//				has_doc_string = Attribute.has_doc_string();
//			}
//		if (true == (has_ref_attr_name = Attribute.has_ref_attr_name())) {
//				ref_attr_name = Attribute.ref_attr_name();
//		}
//		if (true == (has_t = Attribute.has_t())) {
//		const ::onnx::TensorProto& Tensor= Attribute.t();
//				p_t =  new tensor_proto(const_cast<::onnx::TensorProto&>(Tensor));
//		}
//		if (true == (has_t = Attribute.has_t())) {
//		 const ::onnx::TensorProto &Tensor = Attribute.t();
//				 p_t =  new tensor_proto(const_cast<::onnx::TensorProto&>(Tensor));
//			}
//		if (true == (has_i = Attribute.has_i())) {
//				i =  Attribute.i();
//				int_l.push_back(i);
//			}
//		if (true == (has_f = Attribute.has_f())) {
//				f =  Attribute.f();
//				float_l.push_back(f);
//			}
//			if (true == (has_type = Attribute.has_type())) {
//				type =  Attribute.type();
//			}
//		}
//	}attribute_proto_t;
	
 
//	typedef struct node_proto {
//		size_t ByteSizeLong;
	
//		int input_num;
//	std::list<::std::string> input_l;
 
//		int output_num;
//	std::list<::std::string> output_l;
	 
//		int attribute_num;
//	std::list<attribute_proto_t> attribute_l;
	
//		bool has_name;
//		string name;
		
//		bool has_op_type;
//		string op_type;
			
//		bool has_doc_string;
//		string doc_string;
		 
//		bool has_domain;
//		string domain;
		
//		node_proto(onnx::NodeProto &Node)
//	{
//			ByteSizeLong = Node.ByteSizeLong();
//			if (0 < (input_num = Node.input_size())) {
//				::google::protobuf::RepeatedPtrField< ::std::string> input = Node.input();
//				for (auto it = input.begin(); it != input.end(); ++it) {
//					input_l.push_back(*it);
//				}
//			}
//		if (0 < (output_num = Node.output_size())) {
//				::google::protobuf::RepeatedPtrField< ::std::string> output = Node.output();
//				for (auto it = output.begin(); it != output.end(); ++it) {
//			output_l.push_back(*it);
//				}
//		}
//		if (0 < (attribute_num = Node.attribute_size())) {
//		::google::protobuf::RepeatedPtrField< ::onnx::AttributeProto >	attribute = Node.attribute();
//		for (auto it = attribute.begin(); it != attribute.end(); ++it) {
//					attribute_proto_t *p_attribute_tmp = new attribute_proto(*it);
//					attribute_l.push_back(*p_attribute_tmp);
//				}
//		}
//			if (true == (has_name = Node.has_name())) {
//				name = Node.name();
//		}
//		if (true == (has_doc_string = Node.has_doc_string())) {
//				 doc_string = Node.doc_string();
//			}
//		if (true == (has_op_type = Node.has_op_type())) {
//				 op_type = Node.op_type();
//		}
//		if (true == (has_domain = Node.has_domain())) {
//				 domain = Node.domain();
//			}
//		}
//	} node_proto_t;

//	typedef
//	struct graph_proto {
//		size_t ByteSizeLong;
	
//	int node_num;
//	std::list<node_proto_t> node_l;

//	int initializer_size;
//	std::list<tensor_proto_t> initializer_l;
	
//	int input_info_size;
//	std::list<value_info_proto_t *> input_info_l;
	
//	int output_info_size;
//	std::list<value_info_proto_t *> output_info_l;
	
//	int value_info_size;
//	std::list<value_info_proto_t> value_info_l;
	
//	bool has_name;
//	string name;
	
//	bool has_doc_string;
//	string doc_string;
		
//		graph_proto(onnx::GraphProto &Graph)
//	{
//			ByteSizeLong = Graph.ByteSizeLong();
	
//		if (0 < (node_num = Graph.node_size())) {
		 
//			::google::protobuf::RepeatedPtrField< ::onnx::NodeProto > node = Graph.node();
//			for (auto it = node.begin(); it!= node.end(); ++it) {
//					 node_proto_t *p_node_tmp = new node_proto(*it);
//					node_l.push_back(*p_node_tmp);
//				}
//			}
//			if (0 < (initializer_size = Graph.initializer_size())) {
//				::google::protobuf::RepeatedPtrField< ::onnx::TensorProto > initializer = Graph.initializer();
//				for (auto it = initializer.begin(); it != initializer.end(); ++it) {
//					tensor_proto_t *p_tensor_tmp = new tensor_proto(*it);
//					initializer_l.push_back(*p_tensor_tmp);
//				}
//			}
//			if (0 < (input_info_size = Graph.input_size())) {
//			 ::google::protobuf::RepeatedPtrField< ::onnx::ValueInfoProto > input = Graph.input();
//			 for (auto it = input.begin(); it != input.end(); ++it) {
//				 value_info_proto_t *p_value_info_tmp = new value_info_proto(*it);
//				 input_info_l.push_back(p_value_info_tmp);
//			 }
//			}
//			if (0 < (output_info_size = Graph.output_size())) {
//				::google::protobuf::RepeatedPtrField< ::onnx::ValueInfoProto > output = Graph.output();
//				for (auto it = output.begin(); it != output.end(); ++it) {
//					value_info_proto_t *p_value_info_tmp = new value_info_proto(*it);
//					output_info_l.push_back(p_value_info_tmp);
//				}
//		}
//			if (0 < (value_info_size = Graph.value_info_size())) {
//			 ::google::protobuf::RepeatedPtrField< ::onnx::ValueInfoProto > value_info = Graph.value_info();
//			 for (auto it = value_info.begin(); it != value_info.end(); ++it) {
//				 value_info_proto_t *p_value_info_tmp = new value_info_proto(*it);
//				 value_info_l.push_back(*p_value_info_tmp);
//				}
//		}
//			if (true == (has_name = Graph.has_name())) {
//				name = Graph.name();
//			}
//			if (true == (has_doc_string = Graph.has_doc_string())) {
//				doc_string = Graph.doc_string();
//			 }
//		}
//	} graph_proto_t;
	
//	typedef
//	struct operator_set_id_proto {
//		size_t ByteSizeLong;
		
//		bool has_domain;
//		string domain;
			
//		bool has_version;
//		::google::protobuf::int64 version;
		
//		operator_set_id_proto(onnx::OperatorSetIdProto &OperatorSetId )
//	{
//			ByteSizeLong = OperatorSetId.ByteSizeLong();
//			if (true == (has_domain = OperatorSetId.has_domain())) {
//				domain = OperatorSetId.domain();
//			}
//			if (true == (has_version = OperatorSetId.has_version())) {
//				 version = OperatorSetId.version();
//			}
//		}
//	} operator_set_id_proto_t;

	
//	typedef
//	struct string_string_entry_proto {
//		size_t ByteSizeLong;
		
//		bool has_key;
//		string key;
		 
//		bool has_value;
//		string value;
		 
//		string_string_entry_proto(onnx::StringStringEntryProto &StringStringEntry)
//	{
//		if (true == (has_key = StringStringEntry.has_key())) {
//				key = StringStringEntry.key();
//			}
//		if (true == (has_value = StringStringEntry.has_value())) {
//				value = StringStringEntry.value();
//		}
//		}
//	} string_string_entry_proto_t;

//	typedef
//	struct model_proto {
//		size_t ByteSizeLong;
		
//		int opset_import_size;

//		std::list<operator_set_id_proto_t> opset_import_l;
//		int metadata_props_size;
 
//		std::list<string_string_entry_proto_t> metadata_props_l;
//		bool has_producer_name;
//		string producer_name;
	
//		bool has_producer_version;
//		string producer_version;
		
//		bool has_domain;
//		string domain;
		 
//		bool has_doc_string;
//		string doc_string;
 
//		bool has_graph;
//		graph_proto_t *p_graph;
		
//		bool has_ir_version;
//		::google::protobuf::int64 ir_version;
		 
//		bool has_model_version;
//		::google::protobuf::int64 model_version;
		
//		model_proto(onnx::ModelProto &Model )
//	{
//			ByteSizeLong = Model.ByteSizeLong();
		
//		if (0 < (opset_import_size = Model.opset_import_size())) {
//				::google::protobuf::RepeatedPtrField< ::onnx::OperatorSetIdProto > operator_set_id = Model.opset_import();
//			for (auto it = operator_set_id.begin(); it != operator_set_id.end(); ++it) {
//					operator_set_id_proto_t operator_set_id_t = operator_set_id_proto(*it);
//					opset_import_l.push_back(operator_set_id_t);
//				}
//			}
//			if (0 < (metadata_props_size = Model.metadata_props_size())) {
//		::google::protobuf::RepeatedPtrField< ::onnx::StringStringEntryProto > string_string_entry  =  Model.metadata_props();
//		for (auto it = string_string_entry.begin(); it != string_string_entry.end(); ++it) {
//					string_string_entry_proto_t string_string_entry_t = string_string_entry_proto(*it);
//			}
//			}
//			if (true == (has_producer_name = Model.has_producer_name())) {
//				producer_name = Model.producer_name();
//		}
//		if (true == (has_producer_version = Model.has_producer_version())) {
//				producer_version = Model.producer_version();
//		}
//		if (true == (has_domain = Model.has_domain())) {
//				domain = Model.domain();
//		}
//		if (true == (has_doc_string = Model.has_doc_string())) {
//				doc_string = Model.doc_string();
//		}
//		if (true == (has_graph = Model.has_graph())) {
//		const onnx::GraphProto& Graph = Model.graph();
//				p_graph = new graph_proto(const_cast<::onnx::GraphProto&>(Graph));
//		}
//		if (true == (has_ir_version = Model.has_ir_version())) {
//				ir_version = Model.ir_version();
//			}
//		if (true == (has_model_version = Model.has_model_version())) {
//				model_version = Model.model_version();
//			}
//		}
//	} model_proto_t;

 

//	const string attr_name[] =  {
//	"auto_pad",
//	"broadcast",
//	"dilations",
//	"epsilon",
//	"group",
//	"is_test",
//	"kernel_shape",
//	"momentum",
//	"pads"
//	"spatial",
//	"strides",
//	"shape",
//		"SAME_UPPER"
//	};

//  AttributeProto::AttributeType attr_type;
//	extern TensorProto::DataType data_type;

//	const string op_type[] =  {
//	"Conv",
//	"Constant",
//	"BatchNormalization",
//	"Relu",
//	"Reshape",
//	"Add",
//	"AveragePool",
//	"MaxPool",
//	};
	
	
//	template <typename T>
//	struct node_list
//	{
//		T value;
//		struct node_list *p_next;
//	};
	
	
    typedef
    struct intermediate_info {
        size_t num_dims;
        std::vector<int64_t> dim_value;
    } intermediate_info_t;
	

    typedef
    struct intermediate_node
    {
//	unsigned long index;
        string name;
//		struct intermediate_node *p_self;
//		volatile uint32_t *p_addr;
        TensorProto_DataType data_type;
        intermediate_info_t *p_info;
		
        intermediate_node(value_info_proto_t& value_info)
        {
            name = value_info.name;
            data_type = value_info.p_type->p_type_proto_tensor->elem_type;
            tensor_shape_proto_t *p_shape = value_info.p_type->p_type_proto_tensor->p_shape;
            p_info = new intermediate_info;
            p_info->num_dims = p_shape->dim_num;
            p_info->dim_value = p_shape->dim_l;
    }
        intermediate_node(string n)
        {
            name = n;
            data_type = TensorProto_DataType_FLOAT;
            p_info = new intermediate_info_t();
            p_info->dim_value.push_back(2);
            p_info->dim_value.push_back(2);
            p_info->num_dims = p_info->dim_value.size();
        }
    } intermediate_node_t;
	
    typedef
    struct tensor {
        size_t num_dims;
        std::vector<int64_t> dim_value_v;
        int  data_size;

    std::vector<float>* data_float;
    std::vector<int32_t>* data_int32;
    std::vector<double_t>* data_double;
    std::vector<int64_t>* data_int64;
    std::vector<uint64_t>* data_uint64;
    tensor(){
        num_dims = 0;
        data_size = 0;
    }

//	tensor(tensor_proto& t)
//	{
//			num_dims = t.dims_num;
//		dim_value_v = t.dims_v;
//		if (true == t.has_data_type) {
//			if (t.data_type == TensorProto_DataType_FLOAT) {
//					data_size = t.float_data_size;
//					 data_float= &t.float_data_v;
//			}
//			else
//				if (t.data_type == TensorProto_DataType_INT32) {
//					data_size = t.int32_data_size;
//					data_int32 = &t.int32_data_v;
//				}
//				else
//					if (t.data_type == TensorProto_DataType_INT64) {
//					data_size = t.int64_data_size;
//					data_int64 = &t.int64_data_v;
//				}
//				else
//					if (t.data_type == TensorProto_DataType_DOUBLE) {
//					data_size = t.double_data_size;
//					data_double = &t.double_data_v;
//				}
//				if (t.data_type == TensorProto_DataType_UINT64) {
//				 data_size = t.uint64_data_size;
//					data_uint64 = &t.uint64_data_v;
//				}
//		}
//		}
    } tensor_t;

    typedef
    struct weight_node
    {
//	unsigned long index;
        string name;
//		struct weight_node *p_self;

        TensorProto_DataType data_type;
        AttributeProto_AttributeType attr_type;
        struct tensor *p_t;

        weight_node(string n, int i){
            name = n;
            attr_type = AttributeProto_AttributeType_TENSOR;
            p_t = new tensor();
            if(i==0){
                data_type = TensorProto_DataType_DOUBLE;
                p_t->dim_value_v.push_back(2);
                p_t->num_dims=p_t->dim_value_v.size();
                p_t->data_double = new vector<double_t>();
                p_t->data_double->push_back(4.4);
                p_t->data_double->push_back(5.6);
                p_t->data_size = p_t->data_double->size();
            }else{
                data_type = TensorProto_DataType_INT32;
                p_t->dim_value_v.push_back(3);
                p_t->dim_value_v.push_back(2);
                p_t->num_dims=p_t->dim_value_v.size();
                p_t->data_int32 = new vector<int32_t>();
                p_t->data_int32->push_back(0);
                p_t->data_int32->push_back(1);
                p_t->data_int32->push_back(2);
                p_t->data_int32->push_back(3);
                p_t->data_int32->push_back(4);
                p_t->data_int32->push_back(5);
                p_t->data_size = p_t->data_int32->size();
            }
        }
        weight_node(string n){
            name = n;
        }

//		weight_node(node_proto_t &node)
//		{
//			name = node.name;
//			attribute_proto_t attribute = node.attribute_l.front();
//			attr_type = attribute.type;
//			tensor_proto_t *p_t_tmp =  attribute.p_t;
//			if (attr_type == AttributeProto_AttributeType_TENSOR) {
//			data_type= attribute.p_t->data_type;
//		if ((true == attribute.p_t->has_data_type) && (data_type == TensorProto_DataType_FLOAT)) {
//					p_t = new tensor(*p_t_tmp);
//					//cout << "after generate pt in weightNode" << endl;
//					//cout << p_t -> data_size << endl;
//					//cout << (*(p_t -> data))[0] << endl;
//					//cout << p_t << endl;
//			}
//			else
//				if ((true == attribute.p_t->has_data_type) && (data_type == TensorProto_DataType_INT32)) {
//					p_t = new tensor(*p_t_tmp);
//				}
//				else
//				if ((true == attribute.p_t->has_data_type) && (data_type == TensorProto_DataType_INT64)) {
//					p_t = new tensor(*p_t_tmp);
//				}
//				if ((true == attribute.p_t->has_data_type) && (data_type == TensorProto_DataType_DOUBLE)) {
//					p_t = new tensor(*p_t_tmp);
//				}
//				else
//				if ((true == attribute.p_t->has_data_type) && (data_type == TensorProto_DataType_UINT64)) {
//					p_t = new tensor(*p_t_tmp);
//				}
//			}
//		 }
     } weight_node_t;
	

    struct op_node_attr
    {
        string name;
        int num_dims;
        AttributeProto::AttributeType type;
	
        std::list<string> data_string;
        std::vector<float> data_float;
        std::list<int64_t> data_int64;
        op_node_attr(string n, int i){
            name = n;
            if(i==0){
                data_float.push_back(3.33f);
                data_float.push_back(0.9883496761322021f);
                data_float.push_back(4.55667f);
                num_dims = data_float.size();
            }else if(i==1){
                data_int64.push_back(4);
                data_int64.push_back(7);
                num_dims = data_int64.size();
            }else{
                data_string.push_back("ssss");
                data_string.push_back("opk");
                num_dims = data_string.size();
            }

        }
        op_node_attr(string n){
            name = n;
        }
//		op_node_attr(attribute_proto_t &attribute)
//	{
//			if ((true == attribute.has_name) && (true == attribute.has_type)) {
//				name = attribute.name;
//				type = attribute.type;
//		if (type == AttributeProto_AttributeType_FLOAT) {
//						num_dims = 1;
//						data_float =  attribute.float_l;
//			}
//			else
//				if (type == AttributeProto_AttributeType_INT) {
//					 num_dims = 1;
//					  data_int64 = attribute.int_l;
//			}
//				else
//				if (type == AttributeProto_AttributeType_STRING) {
//					 num_dims = 1;
//				 data_string = attribute.string_l;
//			}
//			else
//				if (type == AttributeProto_AttributeType_FLOATS){
//					 num_dims = attribute.floats_size;
//					 data_float =  attribute.float_l;
//			}
//			else
//				if (type == AttributeProto_AttributeType_INTS) {
//						num_dims = attribute.ints_size;
//						data_int64 = attribute.int_l;
//		}
//		else
//				if (type == AttributeProto_AttributeType_STRINGS) {
//						 num_dims = attribute.strings_num;
//					 		data_string = attribute.string_l;
//				}
//		}
//	}
    };

    typedef
    struct op_node
    {
//		unsigned long index;
        string name;
        string type;
//		struct op_node *p_self;
		
//		int merge_num;
//		int split_node;
//		int pirority;
//		int cal_num;
//		bool move_input;
//		bool move_branch_input;
//		bool skip;
//		bool cpu_only;
//		bool next_merge;
//		bool branch_split_start;
//		bool depth_wise;

//		std::vector<google::protobuf::int64> split_prev_dim_val;


        int input_num;
        std::list<string> inputNodeNameList;
		
        int input_intermediate_num;
        std::list<string> inputIntermediateNodeNameList;
        std::vector<struct intermediate_node* > inputIntermediateNodePointerList;
	 
        int input_weight_num;
//		std::list<string> inputWeighNameList;
//		TensorProto_DataType weight_data_type;
	 
        std::vector<weight_node *> inputweightNodePointerlist;

        int output_num;
        std::list<string> outputNodeNameList;
		
        int next_num;
        std::vector<struct op_node* > nextOpNodePointerList;
		
        int prev_num;
        std::vector<struct op_node* > prevOpNodePointerList;
		
        int attribute_num;
        std::list<struct op_node_attr> attrFloatList;
        std::list<struct op_node_attr> attrIntList;
        std::list<struct op_node_attr> attrStringList;

        op_node(string n, string t,string o){
            name = n;
            type = t;
            outputNodeNameList.push_back(o);
            output_num=1;
            next_num = 0;
            prev_num = 0;
            attribute_num = 0;
            input_num = 0;
            input_intermediate_num = 0;
            input_weight_num = 0;
        }

        void add_float(){
            attrFloatList.push_back(op_node_attr("epsilon",0));
            attribute_num++;
        }
        void add_int(){
            attrIntList.push_back(op_node_attr("is_test",1));
            attribute_num++;
        }
        void add_string(){
            attrStringList.push_back(op_node_attr("string",2));
            attribute_num++;
        }
        void add_weight(string n, int i){
            input_weight_num++;
            weight_node * w = new weight_node(n, i);
            inputweightNodePointerlist.push_back(w);
        }
        void add_inter(string n){
            input_intermediate_num++;
            inputIntermediateNodePointerList.push_back(new intermediate_node(n));
        }
	
//		op_node(node_proto_t& node, std::vector<intermediate_node *> intermediate_nodes, std::vector<weight_node*> weight_node)
//		{
//			name = node.name;
//			bool found = false;
//			input_num = node.input_num;
//			type = node.op_type;
//			next_num = 0;
//			prev_num = 0;
//			split_node=0;
//			move_input=0;
//			move_branch_input=0;
//			cpu_only=false;
//			merge_num=0;
//			skip = false;
//			next_merge = false;
//			branch_split_start = false;
//			depth_wise = false;
//			inputNodeNameList.assign(node.input_l.begin(),node.input_l.end());
		 
//			for (auto it = inputNodeNameList.begin(); it!=inputNodeNameList.end(); ++it)
//			{
					
//					intermediate_node * intermediate_node_ptr;
//					for (auto it2= intermediate_nodes.begin(); it2!= intermediate_nodes.end(); ++it2)
//					{
//						if (*it == (*it2)->name)
//						{
//							found = true;
//							intermediate_node_ptr = *it2;
//							break;
//						}
//					}
//					if (true == found)
//					{
//							string *p_intermediate_node_name = new string(*it);
//							inputIntermediateNodeNameList.push_back(*p_intermediate_node_name);
//							// cout << "intermediate_node_ptr.name: " << intermediate_node_ptr->name << endl;
//							inputIntermediateNodePointerList.push_back(intermediate_node_ptr);
//							input_intermediate_num++;
//							found = false;
//					}
//					else
//					{
//						string *p_weight_node_name = new string(*it);
//						inputWeighNameList.push_back(*p_weight_node_name);
//						input_weight_num++;
//						for (auto it3 = weight_node.begin(); it3!= weight_node.end(); ++it3)
//						{
//							if (*p_weight_node_name == (*it3)->name)
//							{
//								inputweightNodePointerlist.push_back( *it3);
//							}
//						}
//					}
//			}

//	 		output_num = node.output_num;
//			outputNodeNameList.assign(node.output_l.begin(),node.output_l.end());
			 
//			if (0 < (attribute_num = node.attribute_num)) {
//				std::list<attribute_proto_t> attribute_l_tmp  = node.attribute_l;
//				for (auto it = attribute_l_tmp.begin(); it != attribute_l_tmp.end(); ++it) {
//					attribute_proto_t attribute_tmp = attribute_proto(*it);
//					if (attribute_tmp.type == AttributeProto_AttributeType_FLOAT) {
//						struct op_node_attr *p_op_node_attr = new op_node_attr(attribute_tmp);
//						attrFloatList.push_back(*p_op_node_attr);
//					}
//					else
//					if (attribute_tmp.type == AttributeProto_AttributeType_INT) {
//						struct op_node_attr *p_op_node_attr = new op_node_attr(attribute_tmp);
//						attrIntList.push_back(*p_op_node_attr);
//					}
//					else
//					if (attribute_tmp.type == AttributeProto_AttributeType_STRING) {
//						struct op_node_attr *p_op_node_attr = new op_node_attr(attribute_tmp);
//						attrStringList.push_back(*p_op_node_attr);
//				}
//				else
//					if (attribute_tmp.type == AttributeProto_AttributeType_FLOATS){
//						struct op_node_attr *p_op_node_attr = new op_node_attr(attribute_tmp);
//						attrFloatList.push_back(*p_op_node_attr);
//				}
//				else
//					if (attribute_tmp.type == AttributeProto_AttributeType_INTS) {
//						struct op_node_attr *p_op_node_attr = new op_node_attr(attribute_tmp);
//						attrIntList.push_back(*p_op_node_attr);
//			}
//			else
//					if (attribute_tmp.type == AttributeProto_AttributeType_STRINGS) {
//						 struct op_node_attr *p_op_node_attr = new op_node_attr(attribute_tmp);
//						 attrStringList.push_back(*p_op_node_attr);
//					}
//					else
//						continue;
						
//				}
//		}
//	}
    } op_node_t;

} 
