#include "stack.hpp"
#include <iostream>

int main(){

    Stack new_stack;
    new_stack.get_size();

    new_stack.push('a');
    new_stack.push('b');
    new_stack.push('c');
    new_stack.push('d');


    std::cout << new_stack.get_size();

    new_stack.reverse();


    std::cout << new_stack.pop();
    std::cout << new_stack.peek()->data;

    return 0;
}