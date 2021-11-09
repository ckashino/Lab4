struct StackFrame
{
    char data;
    StackFrame *link;
};

typedef StackFrame *StackFramePtr;

class Stack
{
public:
    Stack();
    StackFramePtr peek();
    void push(char the_symbol);
    char pop();
    bool empty() const;
    char reverse();
    int get_size() const;
    void push_to_bottom(char the_symbol);

private:
    StackFramePtr top;
};

