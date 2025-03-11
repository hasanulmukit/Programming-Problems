#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node* table[TABLE_SIZE];
} HashMap;

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Initialize hash map
void initializeHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
}

// Insert into hash map
void insert(HashMap* map, int key, int value) {
    int index = hashFunction(key);
    Node* newNode = createNode(key, value);
    if (map->table[index] == NULL) {
        map->table[index] = newNode;
    } else {
        Node* temp = map->table[index];
        while (temp->next != NULL) {
            if (temp->key == key) {
                temp->value = value; // Update value if key already exists
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Get value by key
int get(HashMap* map, int key) {
    int index = hashFunction(key);
    Node* temp = map->table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Key not found
}

// Delete a key-value pair
void deleteKey(HashMap* map, int key) {
    int index = hashFunction(key);
    Node* temp = map->table[index];
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                map->table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key not found.\n");
}

// Print hash map
void printHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = map->table[i];
        while (temp != NULL) {
            printf("(%d -> %d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    HashMap map;
    initializeHashMap(&map);

    int choice, key, value;

    while (1) {
        printf("\n1. Insert\n2. Get\n3. Delete\n4. Print\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(&map, key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = get(&map, key);
                if (value == -1)
                    printf("Key not found.\n");
                else
                    printf("Value: %d\n", value);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(&map, key);
                break;
            case 4:
                printHashMap(&map);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
