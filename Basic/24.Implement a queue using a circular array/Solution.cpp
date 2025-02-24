#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue q(size);

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
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
            cout << "Invalid choice.\n";
        }
    }
}
