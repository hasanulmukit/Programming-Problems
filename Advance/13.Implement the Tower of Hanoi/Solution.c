#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

void moveDisk(Stack* src, Stack* dest, char s, char d) {
    int pole1Top = isEmpty(src) ? -1 : pop(src);
    int pole2Top = isEmpty(dest) ? -1 : pop(dest);

    if (pole1Top == -1) {
        push(src, pole2Top);
        printf("Move disk %d from %c to %c\n", pole2Top, d, s);
    } else if (pole2Top == -1) {
        push(dest, pole1Top);
        printf("Move disk %d from %c to %c\n", pole1Top, s, d);
    } else if (pole1Top > pole2Top) {
        push(src, pole1Top);
        push(src, pole2Top);
        printf("Move disk %d from %c to %c\n", pole2Top, d, s);
    } else {
        push(dest, pole2Top);
        push(dest, pole1Top);
        printf("Move disk %d from %c to %c\n", pole1Top, s, d);
    }
}

void hanoi(int n, Stack* src, Stack* aux, Stack* dest) {
    int moves = (1 << n) - 1;  // 2^n - 1 moves
    char s = 'S', d = 'D', a = 'A';

    if (n % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    for (int i = n; i >= 1; i--) push(src, i);

    for (int i = 1; i <= moves; i++) {
        if (i % 3 == 1)
            moveDisk(src, dest, s, d);
        else if (i % 3 == 2)
            moveDisk(src, aux, s, a);
        else if (i % 3 == 0)
            moveDisk(aux, dest, a, d);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack* src = createStack(n);
    Stack* aux = createStack(n);
    Stack* dest = createStack(n);

    hanoi(n, src, aux, dest);

    free(src->array);
    free(aux->array);
    free(dest->array);
    free(src);
    free(aux);
    free(dest);

    return 0;
}
