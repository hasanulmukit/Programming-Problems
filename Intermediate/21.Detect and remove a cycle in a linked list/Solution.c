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
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int detectAndRemoveCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect Cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (!fast || !fast->next) {
        return 0; // No cycle
    }

    // Remove Cycle
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL; // Break the cycle
    return 1;
}

int main() {
    int n, value, cyclePosition;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL, *cycleNode = NULL;
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

        if (i == cyclePosition - 1) {
            cycleNode = newNode;
        }
    }

    printf("Enter the position to create a cycle (0 for no cycle): ");
    scanf("%d", &cyclePosition);
    if (cyclePosition > 0) {
        tail->next = cycleNode;
    }

    if (detectAndRemoveCycle(head)) {
        printf("Cycle detected and removed.\n");
    } else {
        printf("No cycle detected.\n");
    }

    printf("Updated List: ");
    printList(head);

    return 0;
}
