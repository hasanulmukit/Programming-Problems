#include <iostream>
using namespace std;

// Definition of a tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Recursively build the tree using sentinel (-1).
Node* buildTree() {
    int data;
    cout << "Enter node value (-1 for no node): ";
    cin >> data;
    
    if (data == -1)
        return nullptr;
    
    Node* root = new Node(data);
    cout << "Enter left child of " << data << ":\n";
    root->left = buildTree();
    cout << "Enter right child of " << data << ":\n";
    root->right = buildTree();
    
    return root;
}

// Inorder traversal: Left, Root, Right.
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right.
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root.
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    cout << "Build the binary tree:\n";
    Node* root = buildTree();

    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
