// Write a program in C to convert infix expression to postfix expression using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int is_empty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void infix_to_postfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    char token;
    while ((token = infix[i++]) != '\0') {
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while (!is_empty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Remove '(' from stack
        } else {
            while (!is_empty() && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }
    while (!is_empty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;  // Remove newline character

    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
