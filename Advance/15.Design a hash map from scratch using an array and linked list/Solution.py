class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashMap:
    def __init__(self, table_size=10):
        self.table_size = table_size
        self.table = [None] * table_size

    def hash_function(self, key):
        return key % self.table_size

    def insert(self, key, value):
        index = self.hash_function(key)
        current = self.table[index]
        # Update if key exists
        while current:
            if current.key == key:
                current.value = value
                return
            current = current.next
        # Insert new node at the beginning
        new_node = Node(key, value)
        new_node.next = self.table[index]
        self.table[index] = new_node
        print(f"Inserted ({key} -> {value}) into hash map.")

    def get(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        return None

    def delete(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        prev = None
        while current:
            if current.key == key:
                if prev:
                    prev.next = current.next
                else:
                    self.table[index] = current.next
                print(f"Key {key} removed.")
                return
            prev = current
            current = current.next
        print(f"Key {key} not found.")

    def print_map(self):
        for i, node in enumerate(self.table):
            print(f"Index {i}:", end=" ")
            current = node
            while current:
                print(f"({current.key} -> {current.value})", end=" ")
                current = current.next
            print()

def main():
    hashmap = HashMap()
    while True:
        print("\nHash Map Menu:")
        print("1. Insert")
        print("2. Get")
        print("3. Delete")
        print("4. Print")
        print("5. Exit")
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            key = int(input("Enter key: "))
            value = int(input("Enter value: "))
            hashmap.insert(key, value)
        elif choice == 2:
            key = int(input("Enter key: "))
            result = hashmap.get(key)
            if result is None:
                print("Key not found.")
            else:
                print(f"Value for key {key} is {result}")
        elif choice == 3:
            key = int(input("Enter key to delete: "))
            hashmap.delete(key)
        elif choice == 4:
            hashmap.print_map()
        elif choice == 5:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
