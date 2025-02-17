#include <iostream>
#define MAX 100
using namespace std;

int stack[MAX], top = -1;

void push() {
    if (top == MAX - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    int val;
    cout << "Enter value to push: ";
    cin >> val;
    stack[++top] = val;
    cout << val << " pushed onto stack." << endl;
}

void pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
        return;
    }
    cout << stack[top--] << " popped from stack." << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements:" << endl;
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
