#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void AppendAtEnd(int data)
    {
        Node *node = new Node();
        node->data = data;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = node;
        }
    }

    void AppendAtFront(int data)
    {
        Node *node = new Node();
        node->data = data;
        node->next = head;
        head = node;
    }

    //NO EDGE case are handled
    void AppendAfter(int index, int data)
    {
        Node *current = head;
        int count = 1;
        while (count != index)
        {
            current = current->next;
            count++;
        }
        Node *node = new Node();
        node->data = data;
        node->next = current->next;
        current->next = node;
    }

    void List()
    {
        if (head == NULL)
        {
            std::cout << "List is Empty" << std::endl;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << current->data << std::endl;
        }
    }
};

int main()
{
    LinkedList ll;

    int choice = 1;
    while (choice != 0)
    {
        std::cout << "---------------------------" << std::endl;
        std::cout << "Enter 1 to AppendAtLast : " << std::endl;
        std::cout << "Enter 2 to AppendAtFront : " << std::endl;
        std::cout << "Enter 3 to AppendAfter : " << std::endl;
        std::cout << "Enter 4 to List : " << std::endl;
        std::cout << "Enter 0 to EXIT : " << std::endl;
        std::cin >> choice;
        std::cout << "---------------------------" << std::endl;

        int val,index;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            std::cout << "Enter Value to Append : " << std::endl;
            std::cin >> val;
            ll.AppendAtEnd(val);
            continue;

        case 2:
            std::cout << "Enter Value to Append : " << std::endl;
            std::cin >> val;
            ll.AppendAtFront(val);
            continue;

        case 3:
            std::cout << "Enter Index Number To AppendAfter : " << std::endl;
            std::cin >> index;
            std::cout << "Enter Value : " << std::endl;
            std::cin >> val;
            ll.AppendAfter(index,val);
            continue;;

        case 4:
            ll.List();
            continue;


        default:
            continue;
        }
    }

    return 0;
}