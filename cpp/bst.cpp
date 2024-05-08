#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }

    void Insert(Node* root, int data)
    {
        if (root == NULL)
        {
            Node *node = new Node();
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            root = node;
        }
        else
        {
            Node *current = root;
            if(current->data > data)
            {
                //send to left
                Insert(current->left,data);
            }
            else
            {
                //send to right
                Insert(current->right,data);
            }
        }
    }
};

int main()
{
    Tree *tree = new Tree();
    int choice = 1;
    while (choice != 0)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "Enter 1 to Insert : " << std::endl;
        std::cout << "Enter 2 to PreOrder : " << std::endl;
        std::cout << "Enter 3 to InOrder : " << std::endl;
        std::cout << "Enter 4 to PostOrder : " << std::endl;
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
            // stack.push(val);
            continue;

        case 2:
            // val = stack.pop();
            if (val == -1)
            {
                continue;
            }
            std::cout << "Poped value : " << val << std::endl;
            continue;

        case 3:
            // val = stack.peek();
            if (val == -1)
            {
                continue;
            }
            std::cout << "Peeked value : " << val << std::endl;
            continue;

        default:
            continue;
        }
    }
}