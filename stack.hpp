#include <iostream>

template <class type>
struct StackFrame
{
    type data;
    StackFrame *link;
};

template <class type>
using StackFramePtr = StackFrame<type>*;
// typedef StackFrame<type> *StackFramePtr;

template <class type>
class Stack
{
public:
    ~Stack()
    {
        type next;
        while (!empty())
        {
            next = pop();
        }
    }



    Stack<type> operator=(const Stack &orig_stack){

        StackFramePtr<type> temp_frame = orig_stack.top;
        while(temp_frame != nullptr){
            push_to_bottom(temp_frame->data);
            temp_frame = temp_frame->link;
        }
        return *this;
    }

    Stack(Stack &orig_stack){
        top = nullptr;
        StackFramePtr<type> temp_frame = orig_stack.top;
        while(temp_frame != nullptr){
            push_to_bottom(temp_frame->data);
            temp_frame = temp_frame->link;
        }
    }

    Stack()
    {
        top = nullptr;
    }

    bool empty() const
    {
        return (top == nullptr);
    }

    StackFramePtr<type> peek()
    {
        if (!empty())
            return top;
        else
            return nullptr;
    }

    void push(type the_symbol)
    {

        try
        {
            StackFrame<type> *temp_frame = new StackFrame<type>();
            temp_frame->data = the_symbol;
            temp_frame->link = top;
            top = temp_frame;
        }
        catch (const std::bad_alloc &)
        {
            exit(2);
        }

        
    }

    type pop()
    {
        if (empty())
        {
            std::cout << "popping empty stack";
            exit(1);
        }

        type result = top->data;

        try
        {
            StackFramePtr<type> temp_frame;
            temp_frame = top;
            top = top->link;
            delete temp_frame;
        }
        catch (const std::bad_alloc &)
        {
            exit(2);
        }

        

        return result;
    }

    type reverse()
    {
        if (get_size() > 0)
        {
            type temp_symbol = top->data;
            pop();
            reverse();
            push_to_bottom(temp_symbol);
        }
    }

    int get_size() const
    {
        return get_stack_size(top, 0);
    }

    void push_to_bottom(type the_symbol)
    {
        if (get_size() == 0)
        {
            push(the_symbol);
        }
        else
        {
            type temp_symbol = top->data;
            pop();
            push_to_bottom(the_symbol);
            push(temp_symbol);
        }
    }

private:
    StackFramePtr<type> top;
};

template <class type>
void printStack(Stack<type> S){
        const char *longString = R""""(
        
        
     ,---, 
    ,---.'| 
    |   | : 
    '   : ' 
    :   | | 
    |   ' : 
    ;   ; | 
    '   | ' 
    |   | : 
    '   : ' 
    |   | | 
    ;   : ; 
    |   ,/  
    '---'         
 ___      ___ 
|\  \    /  /|
\ \  \  /  / /
 \ \  \/  / / 
  \ \    / /  
   \ \__/ /   
    \|__|/    
        )"""";


        StackFramePtr<type> temp_frame = S.peek();
        while(temp_frame != nullptr){
            std::cout << temp_frame->data << "\n";
            if(temp_frame->link != nullptr){
                std::cout << longString;
                std::cout << "V\n";
            }

            temp_frame = temp_frame->link;
        }

    }

template <class type>
int get_stack_size(StackFramePtr<type> cur_frame, int current_size)
{
    if (cur_frame == nullptr)
    {
        return current_size;
    }
    else
    {
        get_stack_size(cur_frame->link, current_size + 1);
    }
}
