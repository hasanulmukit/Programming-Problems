#include <iostream>
#define SIZE 100
using namespace std;

class Queue {
    int front, rear, queue[SIZE];

public:
    Queue() : front(-1), rear(-1) {}

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1) front = 0;
            queue[++rear] = value;
            cout << "Inserted: " << value << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Removed: " << queue[front++] << endl;
            if (front > rear) front = rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
