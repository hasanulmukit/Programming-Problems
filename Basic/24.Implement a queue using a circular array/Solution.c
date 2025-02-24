#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} CircularQueue;

void initializeQueue(CircularQueue *q, int size) {
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % q->size);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    int size, choice, value;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    initializeQueue(&q, size);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            displayQueue(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
