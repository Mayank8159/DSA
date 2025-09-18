// Stack implementation in C using linked list
#include <stdio.h>
#include <stdlib.h>
#define MAX 100  // Maximum size of the stack
#include <limits.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL; // Initialize top of stack
int currentSize = 0; // Current size of the stack
// Function to check if the stack is full
bool isFull() {
    return currentSize >= MAX;
}
// Function to check if the stack is empty
bool isEmpty() {
    return top == NULL;
}
// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    currentSize++;
    printf("%d pushed to stack\n", value);
}
// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    free(temp);
    currentSize--;
    printf("%d popped from stack\n", poppedValue);
}