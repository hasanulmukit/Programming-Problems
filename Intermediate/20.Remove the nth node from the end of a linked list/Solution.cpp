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

Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node *fast = dummy, *slow = dummy;

    for (int i = 0; i <= n; i++) {
        if (fast) fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;

    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main() {
    int n, value, pos;

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

    cout << "Enter the position from the end to remove: ";
    cin >> pos;

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, pos);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
