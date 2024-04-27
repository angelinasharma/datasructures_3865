#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    int choice1, size, choice2, choice3, element, position;

    printf("Do you want to create your own linked list or do you want a computer-generated linked list:\n1. to create your own linked list\n2. for computer-generated linked list: ");
    scanf("%d", &choice1);

    if (choice1 == 1 || choice1 == 2) 
    {
        printf("How many elements do you want in the linked list: ");
        scanf("%d", &size);
    } else 
    {
        printf("Invalid input\n");
        return 1;
    }

    if (choice1 == 1) {
        head = (struct Node*)malloc(sizeof(struct Node));
        temp = head;
        for (int i = 0; i < size; i++) 
        {
            printf("Enter an integer element: ");
            scanf("%d", &temp->data);
            if (i < size - 1) {
                temp->next = (struct Node*)malloc(sizeof(struct Node));
                temp = temp->next;
            }
        }
        temp->next = NULL;
        printf("The entered elements are: ");
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    } 
    else if (choice1 == 2) 
    {
        head = (struct Node*)malloc(sizeof(struct Node));
        temp = head;
        for (int i = 0; i < size; i++) {
            temp->data = rand() % (50 + 1);
            if (i < size - 1) {
                temp->next = (struct Node*)malloc(sizeof(struct Node));
                temp = temp->next;
            }
        }
        temp->next = NULL;
        printf("The elements are: ");
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    printf("\nEnter operation to perform on the linked list:\n1. Insertion\n2. Deletion\n3. Viewing\n4. Exit");
    scanf("%d", &choice2);

    switch (choice2) 
    {
        case 1:
            printf("Where do you want to insert the element:\n1. At the beginning\n2. At the end\n3. At a particular location\n4. Exit\n");
            scanf(" %d", &choice3);

            switch (choice3) 
            {
                case 1:
                    printf("Enter the integer element to insert: ");
                    scanf(" %d", &element);

                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->data = element;
                    newNode->next = head;
                    head = newNode;

                    printf("Linked list after insertion: ");
                    temp = head;
                    while (temp != NULL) 
                    {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    break;

                case 2:
                    printf("Enter the integer element to insert: ");
                    scanf(" %d", &element);

                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    newNode->data = element;
                    newNode->next = NULL;

                    temp = head;
                    while (temp->next != NULL) 
                    {
                        temp = temp->next;
                    }
                    temp->next = newNode;

                    printf("Linked list after insertion: ");
                    temp = head;
                    while (temp != NULL) 
                    {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    break;

                case 3:
                    printf("Enter the element to insert: ");
                    scanf(" %d", &element);
                    printf("At what position do you want the element: ");
                    scanf(" %d", &position);


                    if (position >= 0) 
                    {
                        newNode = (struct Node*)malloc(sizeof(struct Node));
                        newNode->data = element;

                        if (position == 0) 
                        {
                            newNode->next = head;
                            head = newNode;
                        } else 
                        {
                            temp = head;
                            for (int i = 0; i < position - 1 && temp != NULL; i++) 
                            {
                                temp = temp->next;
                            }

                            if (temp == NULL) 
                            {
                                printf("Invalid position!\n");
                            } else 
                            {
                                newNode->next = temp->next;
                                temp->next = newNode;
                            }
                        }

                        printf("Linked list after insertion: ");
                        temp = head;
                        while (temp != NULL) 
                        {
                            printf("%d ", temp->data);
                            temp = temp->next;
                        }
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
                    printf("Invalid choice!\n");
            }
            break;

        case 2:
            printf("Where do you want to delete the element:\n1. At the beginning\n2. At the end\n3. At a particular location\n4. Exit\n");
            scanf(" %d", &choice3);

        switch (choice3) {
        case 1:
            if (head != NULL) 
            {
                temp = head;
                head = head->next;
                free(temp);
                printf("Element deleted from the beginning.\n");
            } 
            else 
            {
                printf("Linked list is empty.\n");
            }
            break;

        case 2:
            if (head != NULL) 
            {
                if (head->next == NULL) 
                {
                    free(head);
                    head = NULL;
                } else 
                {
                    struct Node* prev = NULL;
                    temp = head;
                    while (temp->next != NULL) 
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    prev->next = NULL;
                    free(temp);
                }
                printf("Element deleted from the end.\n");
            } else 
            {
                printf("Linked list is empty.\n");
            }
            break;

        case 3:
            printf("Enter the position of the element to delete (0 to %d): ", size - 1);
            scanf("%d", &position);
            if (position >= 0 && position < size) 
            {
                if (position == 0) 
                {
                    temp = head;
                    head = head->next;
                    free(temp);
                } 
                else 
                {
                    struct Node* prev = NULL;
                    temp = head;
                    for (int i = 0; i < position; i++) {
                        prev = temp;
                        temp = temp->next;
                    }
                    prev->next = temp->next;
                    free(temp);
                }
                printf("Element deleted from position %d.\n", position);
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
            printf("Invalid choice!\n");
    }
    break;

        case 3:
            printf("Linked list: ");
            temp = head;
            while (temp != NULL)   
            {
                printf("%d ", temp->data);
                temp = temp->next;
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
