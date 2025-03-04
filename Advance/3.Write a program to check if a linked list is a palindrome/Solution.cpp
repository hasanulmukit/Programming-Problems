#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
}

bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;

    while (temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp) {
        if (temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        append(head, val);
    }

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
