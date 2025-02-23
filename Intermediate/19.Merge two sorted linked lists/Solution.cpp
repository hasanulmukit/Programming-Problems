#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeSortedLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSortedLists(l1, l2->next);
        return l2;
    }
}

int main() {
    int n1, n2, value;

    printf("Enter the number of nodes in the first sorted list: ");
    scanf("%d", &n1);
    struct Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n1; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (!head1) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    printf("Enter the number of nodes in the second sorted list: ");
    scanf("%d", &n2);
    struct Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < n2; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (!head2) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    printf("First List: ");
    printList(head1);
    printf("Second List: ");
    printList(head2);

    struct Node* mergedList = mergeSortedLists(head1, head2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
