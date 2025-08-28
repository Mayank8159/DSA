//write a program to merge two already sorted linked lists
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* merged = NULL;

    // If either list is empty, return the other list
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    // Merge the lists
    if (list1->data < list2->data) {
        merged = list1;
        merged->next = mergeSortedLists(list1->next, list2);
    } else {
        merged = list2;
        merged->next = mergeSortedLists(list1, list2->next);
    }
    return merged;
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert values into the first list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    // Insert values into the second list
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    // Print the original lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Merge the two lists
    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
