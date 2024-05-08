#include <iostream>
#define MAX_SIZE 100

class Queue
{
    private:
        int arr[MAX_SIZE];
        int front;
        int rear;

    public:
        Queue()
        {
            front = -1;
            rear = -1;
        }

        bool isEmpty()
        {
            return (&rear == &front);
        }

        bool isFull()
        {
            return (rear == MAX_SIZE -1);
        }

        int Enqueue(int val)
        {
            if(isFull())
            {
                std::cout << "Queue Overflow" << std::endl;
                return -1;
            }
            arr[++rear] = val;
            return arr[rear];
        }

        int Dequeue()
        {
            if(isEmpty())
            {
                std::cout << "Queue Underflow" << std::endl;
                return -1;
            }
            return arr[++front];
        }

        void Display()
        {
            int current = front + 1;
            while (current <= rear)
            {
                std::cout << arr[current] << " -> ";
                current++;
            }
            std::cout << "null" << std::endl;
        }
};

int main()
{
    Queue queue;

    int choise = 1;

    while (choise != 0)
    {
        std::cout << "---------------------" << std::endl;
        std::cout << "Enter 1 to Enqueue : " << std::endl;
        std::cout << "Enter 2 to Dequeue : " << std::endl;
        std::cout << "Enter 3 to Display : " << std::endl;
        std::cout << "Enter 0 to EXIT : " << std::endl;
        std::cin >> choise;
        std::cout << "------------------" << std::endl;

        int val;

        switch (choise)
        {
        case 0:
            break;
        
        case 1:
            std::cout << "Enter value : " << std::endl;
            std::cin >> val;
            queue.Enqueue(val);
            continue;

        case 2:
            val = queue.Dequeue();
            std::cout << "Dequeue Value : " << val << std::endl;
            continue;

        case 3:
            queue.Display();
            continue;

        default:
            break;
        }
    }
    

    return 0;
}