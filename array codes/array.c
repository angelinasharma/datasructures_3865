#include <stdio.h>
#include <stdlib.h>

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
        for (int i = 0; i < size; i++) {
            printf("%d ", a[i]);
        }
    } else if (choice1 == 2) {
        for (int i = 0; i < size; i++) {
            a[i] = rand() % (50 + 1);
        }
        printf("The elements are: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", a[i]);
        }
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

                    for (int i = size; i > 0; i--) {
                        a[i] = a[i - 1];
                    }
                    a[0] = element;
                    size++;

                    printf("Array after insertion: ");
                    for(int i = 0; i < size; i++)
                    {
                        printf("%d ", a[i]);
                    }
                    break;

                case 2: 
                    printf("Enter the integer element to insert: ");
                    scanf(" %d", &element);
                    
                    a[size] = element;
                    size++;

                    printf("Array after insertion: ");
                    for(int i = 0; i < size; i++)
                    {
                        printf("%d ", a[i]);
                    }
                    break;

                case 3:
                    printf("Enter the element to insert: ");
                    scanf(" %d", &element);
                    printf("At what position do you want the element: ");
                    scanf(" %d", &position);
                    if(position >= 0 && position <= size)
                    {
                        for(int i = size; i > position; i--)
                        {
                            a[i] = a[i - 1];
                        }
                        a[position] = element;
                        size++;

                        printf("Array after insertion: ");
                        for(int i = 0; i < size; i++)
                        {
                            printf("%d ", a[i]);
                        }
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
            printf("What element do you want to delete:\n1. At the beginning\n2. At the end\n3. At a particular location\n3. Exit\n");
            scanf(" %d", &choice3);


            switch(choice3)
            {
                case 1:
                    for(int i = 0; i < size - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }
                    size--;
                    printf("Array after deletion: ");
                    for(int i = 0; i < size; i++)
                    {
                        printf("%d ", a[i]);
                    }
                    break;

                case 2:
                        size--;
                        printf("Array after deletion: ");
                        for (int i = 0; i < size; i++) 
                        {
                            printf("%d ", a[i]);
                        }
                    break;

                case 3:

                    printf("Enter the position of the element to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);
                    if (position >= 0 && position < size)
                    {
                        for (int i = position; i < size - 1; i++)
                        {
                            a[i] = a[i + 1];
                        }
                        size--;
                        printf("Array after deletion: ");
                        for (int i = 0; i < size; i++)
                        {
                            printf("%d ", a[i]);
                        }
                        printf("\n");
                    }
                    else
                    {
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
            for(int i = 0; i < size; i++)
            {
                printf("%d ", a[i]);
            }

            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
