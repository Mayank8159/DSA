//Write a program in C to perform insertion and deletion operations in a doubly linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;

    // If head node holds the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) return;

    // Unlink and delete
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
}

// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printf("Doubly Linked List after insertion:\n");
    displayList(head);

    deleteNode(&head, 20);
    printf("Doubly Linked List after deleting 20:\n");
    displayList(head);

    deleteNode(&head, 10);
    printf("Doubly Linked List after deleting 10:\n");
    displayList(head);

    return 0;
}