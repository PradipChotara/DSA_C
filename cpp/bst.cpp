#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int key)
{
    Node *node = new Node();
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

Node *Insert(Node *root, int key)
{
    if (root == NULL)
    {
        return newNode(key);
    }
    if (key < root->data)
    {
        root->left = Insert(root->left, key);
    }
    if (key >= root->data)
    {
        root->right = Insert(root->right, key);
    }
    return root;
}

void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << " " << root->data;
        Inorder(root->right);
    }
    return;
}

void Preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        cout << " " << root->data;
    }
    Preorder(root->left);
    Preorder(root->right);
}

int main()
{
    int choice = 1;

    Node* root = NULL;
    root = Insert(root,10);

    while (choice != 0)
    {
        std::cout << "\n------------------" << std::endl;
        std::cout << "Enter 1 to Insert : " << std::endl;
        std::cout << "Enter 2 to PreOrder : " << std::endl;
        std::cout << "Enter 3 to InOrder : " << std::endl;
        std::cout << "Enter 4 to PostOrder : " << std::endl;
        std::cout << "Enter 0 to EXIT : " << std::endl;
        std::cin >> choice;
        std::cout << "\n------------------" << std::endl;

        int val;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            std::cout << "Enter Value to Push : " << std::endl;
            std::cin >> val;
            Insert(root,val);
            continue;

        case 2:
            Preorder(root);
            continue;

        case 3:
            Inorder(root);
            continue;

        default:
            continue;
        }
    }
}