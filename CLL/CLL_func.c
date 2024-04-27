#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createLinkedList(int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    for (int i = 0; i < size; i++) {
        printf("Enter an integer element: ");
        scanf("%d", &temp->data);

        if (i < size - 1) {
            temp->next = (struct Node*)malloc(sizeof(struct Node));
            temp = temp->next;
        }
    }

    temp->next = head; // Making it circular
    return head;
}

void insertElement(struct Node** head_ref, int element, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;

    if (position <= 0) {
        newNode->next = *head_ref;

        // Update the last node's next pointer to newNode
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = newNode;

        // Update head to point to the new node
        *head_ref = newNode;
    } else {
        // Insertion at a specific position
        struct Node* temp = *head_ref;
        for (int i = 0; i < position - 1 && temp->next != *head_ref; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteElement(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if (position <= 0) {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        if (temp == *head_ref) {
            free(*head_ref);
            *head_ref = NULL;
        } else {
            temp->next = (*head_ref)->next;
            free(*head_ref);
            *head_ref = temp->next;
        }
        printf("Element deleted from the beginning.\n");
    } else {
        // Deletion at a specific position
        struct Node* temp = *head_ref;
        struct Node* prev = NULL;
        for (int i = 0; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == *head_ref) {
            *head_ref = (*head_ref)->next;
        }

        prev->next = temp->next;
        free(temp);
        printf("Element deleted from position %d.\n", position);
    }
}

void viewLinkedList(struct Node* head) {
    printf("Linked list: ");
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
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
            printf("Generating computer-generated linked list...\n");
            // Generating computer-generated linked list
            head = createLinkedList(size); // For simplicity, reusing createLinkedList function
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
                    printf("Enter the position of the element to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);
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
            exit(0);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
