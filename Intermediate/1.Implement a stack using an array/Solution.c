#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push() {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);
    stack[++top] = val;
    printf("%d pushed onto stack.\n", val);
}

void pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
