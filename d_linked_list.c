#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void printList(struct Node* head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);

int main() {
    struct Node* head = NULL;

    // Insert elements at the beginning
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Doubly Linked List: ");
    printList(head);

    // Insert an element at the end
    insertAtEnd(&head, 6);
    printf("\nAfter inserting 6 at end: ");
    printList(head);

    // Delete a node with key 3
    deleteNode(&head, 3);
    printf("\nAfter deleting node with key 3: ");
    printList(head);

    return 0;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Print the contents of the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// Delete a node with a given key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        return;
    }

    // If the node to be deleted is head node
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key is not found
    if (temp == NULL) {
        return;
    }

    // If the node to be deleted is not a tail node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If the node to be deleted is not a head node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}
