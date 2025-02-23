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

struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node* dummy = createNode(0);
    dummy->next = head;
    struct Node *fast = dummy, *slow = dummy;

    for (int i = 0; i <= n; i++) {
        if (fast) fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    struct Node* toDelete = slow->next;
    slow->next = toDelete->next;
    free(toDelete);

    struct Node* newHead = dummy->next;
    free(dummy);
    return newHead;
}

int main() {
    int n, value, pos;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter the position from the end to remove: ");
    scanf("%d", &pos);

    printf("Original List: ");
    printList(head);

    head = removeNthFromEnd(head, pos);

    printf("Updated List: ");
    printList(head);

    return 0;
}
