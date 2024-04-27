#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void insertElement(int arr[], int *size, int element, int position) {
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void deleteElement(int arr[], int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int choice1, size, choice2, choice3, element, position;

    printf("Do you want to create your own array or do you want a computer-generated array:\n1. to create your own array\n2. for computer-generated array: ");
    scanf("%d", &choice1);

    if (choice1 == 1 || choice1 == 2) {
        printf("How many elements do you want in the array: ");
        scanf("%d", &size);
    } else {
        printf("Invalid input\n");
        return 1;
    }

    int a[size];

    if (choice1 == 1) {
        for (int i = 0; i < size; i++) {
            printf("Enter an integer element: ");
            scanf("%d", &a[i]);
        }
        printf("The entered elements are: ");
        printArray(a, size);
    } else if (choice1 == 2) {
        for (int i = 0; i < size; i++) {
            a[i] = rand() % (50 + 1);
        }
        printf("The elements are: ");
        printArray(a, size);
        printf("\n");
    }

    printf("\nEnter operation to perform on the array:\n1. Insertion\n2. Deletion\n3. Viewing\n4. Exit");
    scanf("%d", &choice2);

    switch (choice2) {
        case 1: 
            printf("Where do you want to insert the element:\n1. At the beginning\n2. At the end\n3. At a particular location\n4. Exit\n");
            scanf(" %d", &choice3);

            switch (choice3) {
                case 1: 
                    printf("Enter the integer element to insert: ");
                    scanf(" %d", &element);
                    insertElement(a, &size, element, 0);
                    printf("Array after insertion: ");
                    printArray(a, size);
                    break;

                case 2: 
                    printf("Enter the integer element to insert: ");
                    scanf(" %d", &element);
                    insertElement(a, &size, element, size);
                    printf("Array after insertion: ");
                    printArray(a, size);
                    break;

                case 3:
                    printf("Enter the element to insert: ");
                    scanf(" %d", &element);
                    printf("At what position do you want the element: ");
                    scanf(" %d", &position);
                    if(position >= 0 && position <= size) {
                        insertElement(a, &size, element, position);
                        printf("Array after insertion: ");
                        printArray(a, size);
                    } else {
                        printf("Invalid position!\n");
                    }
                    break;

                case 4:
                    exit(0);
                    break;

                default:
                    printf("Invalid choice!\n");
            }
            break;

        case 2:
            printf("What element do you want to delete:\n1. At the beginning\n2. At the end\n3. At a particular location\n4. Exit\n");
            scanf(" %d", &choice3);

            switch(choice3) {
                case 1:
                    deleteElement(a, &size, 0);
                    printf("Array after deletion: ");
                    printArray(a, size);
                    break;

                case 2:
                    deleteElement(a, &size, size - 1);
                    printf("Array after deletion: ");
                    printArray(a, size);
                    break;

                case 3:
                    printf("Enter the position of the element to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);
                    if (position >= 0 && position < size) {
                        deleteElement(a, &size, position);
                        printf("Array after deletion: ");
                        printArray(a, size);
                    } else {
                        printf("Invalid position!\n");
                    }
                    break;
                
                case 4:
                    exit(0);
                    break;

                default:
                    printf("Invalid input\n");
                    break;
            }
            break;

        case 3:
            printf("Array elements: ");
            printArray(a, size);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
