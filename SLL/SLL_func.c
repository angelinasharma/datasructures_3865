#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createLinkedList(int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    
    if (size <= 0)
        return NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    head->data = rand() % 100; // Generating random data
    head->next = NULL;
    temp = head;

    for (int i = 1; i < size; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        newNode->data = rand() % 100; // Generating random data
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }

    return head;
}

void insertElement(struct Node** head_ref, int element, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = element;

    if (position == 0) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        struct Node* current = *head_ref;
        int i = 0;
        while (current != NULL && i < position - 1) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("Invalid position!\n");
            free(newNode);
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteElement(struct Node** head_ref, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }

    if (*head_ref == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    struct Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = (*head_ref)->next;
        free(temp);
    } else {
        struct Node* prev = NULL;
        int i = 0;
        while (temp != NULL && i < position) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Invalid position!\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void viewLinkedList(struct Node* head) {
    printf("Linked list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeLinkedList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}

int main() {
    struct Node* head = NULL;

    int choice1, size, choice2, choice3, element, position;

    printf("Do you want to create your own linked list or do you want a computer-generated linked list:\n1. to create your own linked list\n2. for computer-generated linked list: ");
    scanf("%d", &choice1);

    if (choice1 == 1 || choice1 == 2) {
        printf("How many elements do you want in the linked list: ");
        scanf("%d", &size);
    } else {
        printf("Invalid input\n");
        return 1;
    }

    switch (choice1) {
        case 1:
            head = createLinkedList(size);
            break;
        case 2:
            head = createLinkedList(size);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("\nEnter operation to perform on the linked list:\n1. Insertion\n2. Deletion\n3. Viewing\n4. Exit");
    scanf("%d", &choice2);

    switch (choice2) {
        case 1:
            printf("Where do you want to insert the element:\n1. At the beginning\n2. At a particular location\n");
            scanf(" %d", &choice3);

            switch (choice3) {
                case 1:
                    printf("Enter the integer element to insert: ");
                    scanf(" %d", &element);
                    insertElement(&head, element, 0);
                    viewLinkedList(head);
                    break;
                case 2:
                    printf("Enter the integer element to insert: ");
                    scanf(" %d", &element);
                    printf("Enter the position to insert: ");
                    scanf(" %d", &position);
                    insertElement(&head, element, position);
                    viewLinkedList(head);
                    break;
                default:
                    printf("Invalid choice!\n");
            }
            break;

        case 2:
            printf("Where do you want to delete the element:\n1. At the beginning\n2. At a particular location\n");
            scanf(" %d", &choice3);

            switch (choice3) {
                case 1:
                    deleteElement(&head, 0);
                    viewLinkedList(head);
                    break;
                case 2:
                    printf("Enter the position to delete: ");
                    scanf(" %d", &position);
                    deleteElement(&head, position);
                    viewLinkedList(head);
                    break;
                default:
                    printf("Invalid choice!\n");
            }
            break;

        case 3:
            viewLinkedList(head);
            break;

        case 4:
            freeLinkedList(&head);
            printf("Memory freed. Exiting program.\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
