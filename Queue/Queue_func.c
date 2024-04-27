#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue q;

void enqueue(int value) {
    if (q.rear == MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (q.front == -1) {
            q.front = 0;
        }
        q.rear++;
        q.items[q.rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

void dequeue() {
    if (q.front == -1) {
        printf("Queue Underflow!\n");
    } else {
        printf("%d dequeued from queue\n", q.items[q.front]);
        if (q.front == q.rear) {
            q.front = -1;
            q.rear = -1;
        } else {
            q.front++;
        }
    }
}

void display() {
    if (q.front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.items[i]);
        }
        printf("\n");
    }
}

int main() {
    q.front = -1;
    q.rear = -1;

    int choice, value;

    do {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
