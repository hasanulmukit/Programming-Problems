#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

void init(MinStack *ms) {
    ms->top = -1;
}

void push(MinStack *ms, int value) {
    if (ms->top == MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    ms->stack[++ms->top] = value;
    if (ms->top == 0 || value < ms->minStack[ms->top - 1]) {
        ms->minStack[ms->top] = value;
    } else {
        ms->minStack[ms->top] = ms->minStack[ms->top - 1];
    }
    printf("Pushed: %d\n", value);
}

void pop(MinStack *ms) {
    if (ms->top == -1) {
        printf("Stack underflow.\n");
        return;
    }
    printf("Popped: %d\n", ms->stack[ms->top--]);
}

int getMin(MinStack *ms) {
    if (ms->top == -1) {
        printf("Stack is empty.\n");
        return INT_MAX;
    }
    return ms->minStack[ms->top];
}

int main() {
    MinStack ms;
    init(&ms);

    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Get Minimum\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&ms, value);
                break;
            case 2:
                pop(&ms);
                break;
            case 3:
                printf("Minimum: %d\n", getMin(&ms));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
