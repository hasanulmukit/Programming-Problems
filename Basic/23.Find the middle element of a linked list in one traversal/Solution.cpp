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

void findMiddle(Node* head) {
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow) {
        cout << "The middle element is: " << slow->data << endl;
    }
}

int main() {
    int n, value;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node *head = nullptr, *tail = nullptr;

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
    }

    cout << "Original List: ";
    printList(head);

    findMiddle(head);

    return 0;
}
