#include "stack.hpp"
#include <iostream>
#include <string>

bool isBlankLine(std::string const& input);

int main(){

    Stack<int> sint1; 
    sint1.push(1);    
    sint1.push(2);    
    sint1.push(3);
    sint1.push(4);
    sint1.push(5);
    sint1.push(6);

    Stack<int> sint2;
    sint2 = sint1;

    sint1.reverse();
    std::cout << "sint1\n-----";
    printStack(sint1);

    printf("%s", KNRM);
    std::cout << "\n\nsint2\n-----";
    printStack(sint2);

    Stack<double> sdouble1;
    
    sdouble1.push(1.5);
    sdouble1.push(2.5);
    sdouble1.push(3.5);
    sdouble1.push(4.5);
    sdouble1.push(5.5);
    sdouble1.push(6.5);

    printf("%s", KNRM);
    std::cout << "\n\nsdouble1\n--------";
    printStack(sdouble1);

    Stack<double> sdouble2(sdouble1);
    sdouble2.reverse();

    printf("%s", KNRM);
    std::cout << "\n\nsdouble2 top\n------------\n";
    printf("%s", KBLU);
    std::cout << sdouble2.peek()->data;


    std::string userInput;
   
    while (1) {
        printf("%s", KNRM);
        std::cout << "\n\n\n\nEnter a string: ";
        printf("%s", KCYN);
        std::getline(std::cin, userInput);

        if (isBlankLine(userInput)) { std::cout << "Nothing was inputted, please try again"; }
        else break;
    }

    Stack<char> palindrome; 
    for (int i = 0; i < userInput.size(); i++)
    {
        palindrome.push(userInput[i]); 
    }
    
    printf("%s", KNRM);
    std::cout << std::endl << "\n\nHere is the palindrome\n----------------------\n";
    printf("%s", KCYN);
    std::cout << userInput;

    printInline(palindrome);

    // StackFrame<char>* node = palindrome.peek();
    // while (node != NULL)
    // {
    //     std::cout << node->data;
    //     node = node->link;
    // }
    std::cout << std::endl;
    printf("%s", KNRM);

    return 0;
}

bool isBlankLine(std::string const& input)
{
    auto temp = input.c_str();
    for (temp; *temp; ++temp)
    {
        if (!isspace(*temp)) return false;
    }
    return true;
}
