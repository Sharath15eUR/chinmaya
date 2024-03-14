#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("\nThe stack is full!");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nThe stack is Empty!");
        return '\0'; 
    } else {
        char poppedItem = stack->items[stack->top];
        stack->top--;
        return poppedItem;
    }
}


void reverseString(char* inputString) 
{
    int length = strlen(inputString);
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < length; i++) 
    {
        push(&stack, inputString[i]);
    }

    for (int i = 0; i < length; i++) {
        inputString[i] = pop(&stack);
    }
}

int main() {
    char inputString[MAX_SIZE];

    printf("Enter a string: ");
    fgets(inputString, MAX_SIZE, stdin);

    reverseString(inputString);
    printf("Reversed string: %s", inputString);

    return 0;
}
