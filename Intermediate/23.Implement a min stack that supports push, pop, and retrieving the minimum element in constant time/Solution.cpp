#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int value) {
        mainStack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (mainStack.empty()) {
            cout << "Stack underflow." << endl;
            return;
        }
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        cout << "Popped: " << mainStack.top() << endl;
        mainStack.pop();
    }

    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty." << endl;
            return INT_MAX;
        }
        return minStack.top();
    }
};

int main() {
    MinStack ms;
    int choice, value;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Get Minimum\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                ms.push(value);
                break;
            case 2:
                ms.pop();
                break;
            case 3:
                cout << "Minimum: " << ms.getMin() << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
