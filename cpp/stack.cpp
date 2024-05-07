#include <iostream>
#define MAX_SIZE 100

class Stack{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE-1;
    }

    void push(int data)
    {
        if(isFull())
        {
            std::cout << "---Stack Overflow---\n";
            return;
        }
        arr[++top] = data;
    }

    int pop()
    {
        if(isEmpty())
        {
            std::cout << "--Stack Undeflow---\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if(isEmpty())
        {
            std::cout << "--Stack Undeflow---\n";
            return -1;
        }
        return arr[top];
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.pop() << std::endl;
    std::cout << stack.peek() << std::endl;

    return 0;
}