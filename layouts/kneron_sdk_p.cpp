#include "kneron_sdk_p.h"
CNN_P::CNN_P(){
    int count = 0;
    p_input = new value_info_proto("input");
    p_output = new value_info_proto("output");
    p_start_node = new op_node("starter","Conv",to_string(count));
    p_start_node->add_inter(p_input->name);
    count++;
    p_start_node->add_weight("conv1_weight",0);
    p_start_node->add_float();
    op_node_t* ender = new op_node_t("ender", "Relu",to_string(count));
    ender->add_inter(p_start_node->outputNodeNameList.front());
    ender->add_weight("cc_weight2",1);
    count++;
    ender->prev_num = 1;
    p_start_node->next_num = 1;
    p_start_node->nextOpNodePointerList.push_back(ender);
    op_node_t* ender2 = new op_node_t("ender2", "Relu",p_output->name);
    vector<string> names;
    count = addPath(names,ender,ender2,count);
    names.push_back("aa");
    names.push_back("ff");
    count = addPath(names, ender,ender2,count);
    names[0]="lll";
    names[1]="gh";
    names.push_back("cc");
    count = addPath(names,ender,ender2,count);
    count = addPath(names,ender,ender2,count);
    count = addPath(names,ender,ender2,count);
}
int CNN_P::addPath(vector<string> &names, op_node_t* parent, op_node_t* child, int count){
    child->prev_num++;
    op_node_t* curr = parent;
    for(auto it=names.begin();it!=names.end();++it){
        curr->next_num++;
        curr->nextOpNodePointerList.push_back(new op_node_t(*it,"MaxPool",to_string(count)));
        curr = curr->nextOpNodePointerList.back();
        curr->prev_num = 1;
        curr->add_inter(to_string(count));
        count++;
    }
    curr->next_num++;
    curr->nextOpNodePointerList.push_back(child);
    child->add_inter(curr->outputNodeNameList.front());
    return count;
}
