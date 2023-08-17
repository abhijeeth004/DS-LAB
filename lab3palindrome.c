#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char data[MAX_SIZE];
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char c) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = c;
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        push(&stack, input[i]);
    }

    char reversed[MAX_SIZE];
    for (int i = 0; i < length; i++) {
        reversed[i] = pop(&stack);
    }
    reversed[length] = '\0';

    if (strcmp(input, reversed) == 0) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}
