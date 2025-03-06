#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, -__INT_MAX__, __INT_MAX__);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    if (isBST(root))
        printf("The tree is a valid BST.\n");
    else
        printf("The tree is not a valid BST.\n");

    return 0;
}
