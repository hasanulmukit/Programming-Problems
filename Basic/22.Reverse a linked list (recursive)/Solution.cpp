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

Node* reverseList(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
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

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
