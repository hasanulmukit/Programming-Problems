#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *stack, int value) {
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->arr[stack->top--];
}

int evaluatePostfix(char *expression) {
    Stack stack = {.top = -1};
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            switch (expression[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                case '^': push(&stack, pow(val1, val2)); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char expression[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
