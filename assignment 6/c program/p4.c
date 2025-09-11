//Write a program in C to implement deletion and insertion of elements at different positions in a singly circular linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head; // Make it circular
}

// Delete a node by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) return;

    struct Node* current = *head;
    struct Node* prev = NULL;

    // If head node holds the value
    if (current->data == value) {
        // If there's only one node
        if (current->next == *head) {
            free(current);
            *head = NULL;
            return;
        }
        // Find the last node to update its next pointer
        while (current->next != *head)
            current = current->next;
        struct Node* temp = *head;
        current->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the value
    prev = *head;
    current = (*head)->next;
    while (current != *head && current->data != value) {
        prev = current;
        current = current->next;
    }

    // If not found
    if (current == *head) return;

    // Unlink and delete
    prev->next = current->next;
    free(current);
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

// Main function
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    displayList(head);

    deleteNode(&head, 20);
    displayList(head);

    deleteNode(&head, 10);
    displayList(head);

    deleteNode(&head, 30);
    displayList(head);

    return 0;
}