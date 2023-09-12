#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack is full. Cannot push %d.\n", value);
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack is empty.\n");
        return -1; // You can choose an appropriate error value
    }
}

void convertToBase(int decimalNumber, int base) {
    Stack stack;
    initialize(&stack);

    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;
        push(&stack, remainder);
        decimalNumber /= base;
    }

    printf("Converted number in base %d: ", base);
    while (!isEmpty(&stack)) {
        int digit = pop(&stack);
        printf("%d", digit);
    }
    printf("\n");
}

int main() {
    int decimalNumber, base;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base (e.g., 2 for binary, 8 for octal, 16 for hexadecimal): ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Invalid base.\n");
        return 1;
    }

    convertToBase(decimalNumber, base);

    return 0;
}
