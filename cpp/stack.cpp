#include <iostream>
#define MAX_SIZE 100

class Stack
{
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
        return top == MAX_SIZE - 1;
    }

    void push(int data)
    {
        if (isFull())
        {
            std::cout << "---Stack Overflow---\n";
            return;
        }
        arr[++top] = data;
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "--Stack Undeflow---\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
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

    // stack.push(10);
    // stack.push(20);
    // stack.push(30);

    // std::cout << stack.pop() << std::endl;
    // std::cout << stack.peek() << std::endl;

    int choice = 1;

    while (choice != 0)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "Enter 1 to Push : " << std::endl;
        std::cout << "Enter 2 to Pop : " << std::endl;
        std::cout << "Enter 3 to Peek : " << std::endl;
        std::cout << "Enter 0 to EXIT : " << std::endl;
        std::cin >> choice;
        std::cout << "------------------" << std::endl;

        int val;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            std::cout << "Enter Value to Push : " << std::endl;
            std::cin >> val;
            stack.push(val);
            continue;

        case 2:
            val = stack.pop();
            if(val == -1)
            {
                continue;
            }
            std::cout << "Poped value : " << val << std::endl;
            continue;

        case 3:
            val = stack.peek();
            if(val == -1)
            {
                continue;
            }
            std::cout << "Peeked value : " << val << std::endl;
            continue;

        default:
            continue;
        }
    }

    return 0;
}