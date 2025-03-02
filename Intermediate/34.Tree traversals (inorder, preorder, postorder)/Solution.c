#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node.
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node.
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursively build the tree.
// Sentinel value: -1 means no node.
Node* buildTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;
    
    Node* root = createNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = buildTree();
    printf("Enter right child of %d:\n", data);
    root->right = buildTree();
    
    return root;
}

// Inorder traversal: Left, Root, Right.
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right.
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root.
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    printf("Build the binary tree:\n");
    Node* root = buildTree();

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
