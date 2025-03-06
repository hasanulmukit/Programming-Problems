#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool detectCycle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    int n, val, pos;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    cout << "Enter the position to create a cycle (0 for no cycle): ";
    cin >> pos;
    if (pos > 0) {
        Node* temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        tail->next = temp;
    }

    if (detectCycle(head))
        cout << "Cycle detected in the linked list.\n";
    else
        cout << "No cycle detected in the linked list.\n";

    return 0;
}
