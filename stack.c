#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Function to push a position onto the stack
void push(Stack *stack, Position pos) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = pos;
}

// Function to pop a position from the stack
void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to peek at the top position of the stack
void peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to clear the stack
void clear(Stack *stack) {
    stack->top = -1;
}