//Give a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a positive integer smaller than or equal to length of the linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void left_shift(struct Node** head_ref, int k) {
    if (*head_ref == NULL || k <= 0) return;

    struct Node* current = *head_ref;
    int length = 1;

    // Find the last node and the length of the list
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // If k is greater than length, normalize it
    k = k % length;
    if (k == 0) return;

    // Find the new head after k shifts
    struct Node* new_head = *head_ref;
    struct Node* prev = NULL;

    for (int i = 0; i < k; i++) {
        prev = new_head;
        new_head = new_head->next;
    }

    // Update the links
    current->next = *head_ref;
    *head_ref = new_head;
    prev->next = NULL;
}

int main() {
    struct Node* head = NULL;
    // Create the linked list and populate it
    for (int i = 1; i <= 5; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    int k = 2;  // Number of positions to left shift
    left_shift(&head, k);

    // Print the modified linked list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}

