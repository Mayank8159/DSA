//Write a program in C to check whether number of opening'(' and closing')' parentheses are equal or not in an expression using stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char expression[MAX];
    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(') {
            push('(');
        } else if (expression[i] == ')') {
            if (is_empty()) {
                printf("Unmatched closing parenthesis found.\n");
                return 0;
            }
            pop();
        }
    }

    if (is_empty()) {
        printf("Number of opening and closing parentheses are equal.\n");
    } else {
        printf("Unmatched opening parenthesis found.\n");
    }

    return 0;
}
