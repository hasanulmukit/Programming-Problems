class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("NULL")

def reverse_list(head):
    prev = None
    current = head

    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node

    return prev

if __name__ == "__main__":
    n = int(input("Enter the number of nodes: "))
    head = None
    tail = None

    for i in range(n):
        value = int(input(f"Enter value for node {i + 1}: "))
        new_node = Node(value)
        if not head:
            head = tail = new_node
        else:
            tail.next = new_node
            tail = new_node

    print("Original List:")
    print_list(head)

    head = reverse_list(head)

    print("Reversed List:")
    print_list(head)
