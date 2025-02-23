#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

bool detectAndRemoveCycle(Node* head) {
    Node *slow = head, *fast = head;

    // Detect Cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (!fast || !fast->next) return false; // No cycle

    // Remove Cycle
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr; // Break the cycle
    return true;
}

int main() {
    int n, value, cyclePosition;

    cout << "Enter the number of nodes: ";
    cin >> n;

    Node *head = nullptr, *tail = nullptr, *cycleNode = nullptr;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (i == cyclePosition - 1) {
            cycleNode = newNode;
        }
    }

    cout << "Enter the position to create a cycle (0 for no cycle): ";
    cin >> cyclePosition;
    if (cyclePosition > 0) {
        tail->next = cycleNode;
    }

    if (detectAndRemoveCycle(head)) {
        cout << "Cycle detected and removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    cout << "Updated List: ";
    printList(head);

    return 0;
}
