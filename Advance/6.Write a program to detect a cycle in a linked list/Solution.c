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

int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

int main() {
    int n, val, pos;
    struct Node *head = NULL, *tail = NULL, *cycleNode = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        if (i == 0)
            cycleNode = newNode;
    }

    printf("Enter the position to create a cycle (0 for no cycle): ");
    scanf("%d", &pos);
    if (pos > 0) {
        struct Node* temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        tail->next = temp;
    }

    if (detectCycle(head))
        printf("Cycle detected in the linked list.\n");
    else
        printf("No cycle detected in the linked list.\n");

    return 0;
}
