#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

bool isBSTUtil(Node* root, int min, int max) {
    if (root == nullptr)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    if (isBST(root))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is not a valid BST." << endl;

    return 0;
}
