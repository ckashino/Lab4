#include "stack.hpp"
#include <iostream>

int main(){

    Stack<float> new_stack;
    new_stack.get_size();

    new_stack.push(1.25);
    new_stack.push(2.25);
    new_stack.push(3.75);
    new_stack.push(4.75);




    Stack<float> new_stack2;
    new_stack2 = new_stack;
    printStack(new_stack2);
    // std::cout << new_stack.empty();
    // std::cout << new_stack.peek()->data;

    return 0;
}