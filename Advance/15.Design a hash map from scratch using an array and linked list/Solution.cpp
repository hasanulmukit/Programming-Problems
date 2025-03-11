#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10; // You can adjust the table size as needed

// Node structure for linked list
struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
private:
    vector<Node*> table;  // Array of linked list heads

    // Simple hash function: modulo TABLE_SIZE
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashMap() {
        table.resize(TABLE_SIZE, nullptr);
    }
    
    // Insert key-value pair; if key exists, update its value.
    void insert(int key, int value) {
        int index = hashFunction(key);
        Node* head = table[index];
        
        // Check if key already exists and update
        while (head) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        // Key not found, so create a new node and insert at beginning
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Inserted (" << key << " -> " << value << ") into hash map." << endl;
    }
    
    // Retrieve value by key; returns true if found and sets the value, false otherwise.
    bool get(int key, int &value) {
        int index = hashFunction(key);
        Node* head = table[index];
        while (head) {
            if (head->key == key) {
                value = head->value;
                return true;
            }
            head = head->next;
        }
        return false;
    }
    
    // Delete a key-value pair from the hash map.
    void remove(int key) {
        int index = hashFunction(key);
        Node* head = table[index];
        Node* prev = nullptr;
        while (head) {
            if (head->key == key) {
                if (prev == nullptr)
                    table[index] = head->next;
                else
                    prev->next = head->next;
                delete head;
                cout << "Key " << key << " removed." << endl;
                return;
            }
            prev = head;
            head = head->next;
        }
        cout << "Key " << key << " not found." << endl;
    }
    
    // Print the entire hash map
    void printMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* head = table[i];
            while (head) {
                cout << "(" << head->key << " -> " << head->value << ") ";
                head = head->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap map;
    int choice;
    
    while (true) {
        cout << "\nHash Map Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Get\n";
        cout << "3. Delete\n";
        cout << "4. Print\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            int key, value;
            cout << "Enter key and value: ";
            cin >> key >> value;
            map.insert(key, value);
        } else if (choice == 2) {
            int key, value;
            cout << "Enter key: ";
            cin >> key;
            if (map.get(key, value))
                cout << "Value for key " << key << " is " << value << endl;
            else
                cout << "Key not found." << endl;
        } else if (choice == 3) {
            int key;
            cout << "Enter key to delete: ";
            cin >> key;
            map.remove(key);
        } else if (choice == 4) {
            map.printMap();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    
    return 0;
}
