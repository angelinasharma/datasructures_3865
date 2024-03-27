#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createLinkedList(int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

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

    return head;
}

void displayLinkedList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* insertNode(struct Node* head, int position, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* deleteNode(struct Node* head, int position) {
    if (position == 0) {
        if (head != NULL) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        } else {
            printf("Linked list is empty.\n");
        }
        return head;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    struct Node* head = NULL;
    int size, choice, position, element;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &size);
    head = createLinkedList(size);
    displayLinkedList(head);

    do {
        printf("\nEnter operation to perform on the linked list:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. View\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position to insert the element: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                head = insertNode(head, position, element);
                displayLinkedList(head);
                break;

            case 2:
                printf("Enter the position to delete the element: ");
                scanf("%d", &position);
                head = deleteNode(head, position);
                displayLinkedList(head);
                break;

            case 3:
                displayLinkedList(head);
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
