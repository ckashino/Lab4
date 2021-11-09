#include "stack.hpp"
#include <iostream>

int get_stack_size(StackFramePtr cur_frame, int current_size){
    if (cur_frame == nullptr)
    {
        return current_size;
    }
    else{
        get_stack_size(cur_frame->link, current_size + 1);
    }
}
int Stack::get_size() const{
    return get_stack_size(top, 0);
}
void Stack::push_to_bottom(char the_symbol){
    if(get_size() == 0){ 
        push(the_symbol);
    }
    else{
        char temp_symbol = top->data;
        pop();
        push_to_bottom(the_symbol);
        push(temp_symbol);
    }
}
char Stack::reverse(){
    if(get_size() > 0){
        char temp_symbol = top->data;
        pop();
        reverse();
        push_to_bottom(temp_symbol);
    }
}
Stack::Stack() {    
    top = nullptr;
}   
bool Stack::empty() const{

    return (top == nullptr);

}
void Stack::push(char the_symbol){
    StackFrame *temp_frame = new StackFrame();
    temp_frame->data = the_symbol;
    temp_frame->link = top;
    top = temp_frame;
}
StackFramePtr Stack::peek(){
    if(!empty())
        return top;
    else
        return nullptr;
}
char Stack::pop(){
    if(empty()){
        std::cout << "popping empty stack";
        exit(1);
    }
    char result = top->data;

    StackFramePtr temp_frame;
    temp_frame = top;
    top = top->link;

    delete temp_frame;

    return result;
}

