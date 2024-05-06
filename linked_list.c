#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node *list, int data) {
    Node *newNode = createNode(data);
    newNode->next = list;
    return newNode;
}

Node* insertAtEnd(Node *list, int data) {
    Node *newNode = createNode(data);
    if (list == NULL) {
        return newNode;
    }
    Node *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return list;
}

void displayList(Node *list) {
    Node *current = list;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *list = NULL;

    list = insertAtBeginning(list, 10);
    list = insertAtBeginning(list, 20);
    list = insertAtEnd(list, 30);

    printf("Linked List: ");
    displayList(list);

    return 0;
}
