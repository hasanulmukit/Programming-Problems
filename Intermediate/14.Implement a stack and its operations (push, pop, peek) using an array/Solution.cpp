#include <iostream>
#define MAX 100
using namespace std;

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack overflow!" << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into the stack." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
        } else {
            cout << arr[top--] << " popped from the stack." << endl;
        }
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.peek();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
