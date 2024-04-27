#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

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
            case 1:
                if (top == MAX_SIZE - 1) {
                    printf("Stack Overflow!\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                    printf("%d pushed to stack\n", value);
                }
                break;
            case 2:
                if (top == -1) {
                    printf("Stack Underflow!\n");
                } else {
                    printf("%d popped from stack\n", stack[top]);
                    top--;
                }
                break;
            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Top element is %d\n", stack[top]);
                }
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
