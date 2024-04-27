#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int main() {
    int choice, value;

    do {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                if (newNode == NULL) {
                    printf("Memory allocation failed\n");
                    break;
                }
                printf("Enter value to push: ");
                scanf("%d", &value);
                newNode->data = value;
                newNode->next = top;
                top = newNode;
                printf("%d pushed to stack\n", value);
                break;
            }
            case 2: {
                if (top == NULL) {
                    printf("Stack Underflow!\n");
                    break;
                }
                struct Node* temp = top;
                top = top->next;
                printf("%d popped from stack\n", temp->data);
                free(temp);
                break;
            }
            case 3: {
                if (top == NULL) {
                    printf("Stack is empty\n");
                    break;
                }
                printf("Top element is %d\n", top->data);
                break;
            }
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
