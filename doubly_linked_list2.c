#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node *createLinkedList(int size, int choice) {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    int i, data;
    printf("Enter the elements for the linked list:\n");
    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        if (head == NULL) {
            head = createNode(data);
            temp = head;
        } else {
            temp->next = createNode(data);
            temp->next->prev = temp;
            temp = temp->next;
        }
    }
    if (choice == 1) {
        printf("The entered elements are: ");
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    return head;
}

void displayLinkedList(struct Node *head) {
    printf("Linked list: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *insertNode(struct Node *head, int position, int element) {
    struct Node *newNode = createNode(element);
    if (position == 0) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }
    struct Node *temp = head;
    int i;
    for (i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node *deleteNode(struct Node *head, int position) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return head;
    }
    if (position == 0) {
        struct Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Element deleted from the beginning.\n");
        return head;
    }
    struct Node *temp = head;
    int i;
    for (i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return head;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Element deleted from position %d.\n", position);
    return head;
}

int main() {
    struct Node *head = NULL;
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
    if (choice1 == 1) {
        head = createLinkedList(size, 1);
    } else if (choice1 == 2) {
        head = createLinkedList(size, 0);
    }
    do {
        printf("\nEnter operation to perform on the linked list:\n1. Insertion\n2. Deletion\n3. Viewing\n4. Exit\n");
        scanf("%d", &choice2);
        switch (choice2) {
            case 1:
                printf("Where do you want to insert the element:\n1. At the beginning\n2. At the end\n3. At a particular location\n4. Exit\n");
                scanf(" %d", &choice3);
                switch (choice3) {
                    case 1:
                        printf("Enter the integer element to insert: ");
                        scanf(" %d", &element);
                        head = insertNode(head, 0, element);
                        displayLinkedList(head);
                        break;
                    case 2:
                        printf("Enter the integer element to insert: ");
                        scanf(" %d", &element);
                        head = insertNode(head, size, element);
                        displayLinkedList(head);
                        break;
                    case 3:
                        printf("Enter the element to insert: ");
                        scanf(" %d", &element);
                        printf("At what position do you want the element: ");
                        scanf(" %d", &position);
                        if (position >= 0 && position <= size) {
                            head = insertNode(head, position, element);
                            displayLinkedList(head);
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
                printf("Where do you want to delete the element:\n1. At the beginning\n2. At the end\n3. At a particular location\n4. Exit\n");
                scanf(" %d", &choice3);
                switch (choice3) {
                    case 1:
                        head = deleteNode(head, 0);
                        displayLinkedList(head);
                        break;
                    case 2:
                        head = deleteNode(head, size - 1);
                        displayLinkedList(head);
                        break;
                    case 3:
                        printf("Enter the position of the element to delete (0 to %d): ", size - 1);
                        scanf("%d", &position);
                        if (position >= 0 && position < size) {
                            head = deleteNode(head, position);
                            displayLinkedList(head);
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
            case 3:
                displayLinkedList(head);
                break;
            case 4:
                exit(0);
                break;
        }
    }while(choice3 != 4);

    return 0;
}