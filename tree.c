#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
void inOrderTraversal(struct Node* root);
void preOrderTraversal(struct Node* root);
void postOrderTraversal(struct Node* root);
void insertNode(struct Node** root, int data);
struct Node* searchNode(struct Node* root, int key);

int main() {
    struct Node* root = NULL;

    // Create a binary tree
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 70);
    insertNode(&root, 60);
    insertNode(&root, 80);

    // Print the tree in different orders
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\nPre-order traversal: ");
    preOrderTraversal(root);
    printf("\nPost-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    // Search for a node
    struct Node* foundNode = searchNode(root, 40);
    if (foundNode != NULL) {
        printf("Node with key 40 found!\n");
    } else {
        printf("Node with key 40 not found.\n");
    }

    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal (left, root, right)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal (root, left, right)
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal (left, right, root)
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Insert a node in the binary tree (recursive)
void insertNode(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else {
        insertNode(&(*root)->right, data);
    }
}

// Search for a node in the binary tree (recursive)
struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}
