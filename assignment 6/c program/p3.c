//Write a program in C to implement a doubly circular linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Add node at the end
void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        // If the list is empty, initialize it
        newNode->prev = newNode;
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Insert the new node at the end
        struct Node* tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

// Main function
int main() {
    struct Node* head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);

    displayList(head);

    return 0;
}