#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int isFull(Queue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int frontValue = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return frontValue;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Front element after dequeue: %d\n", peek(&queue));

    return 0;
}
