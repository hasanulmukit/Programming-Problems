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

def remove_nth_from_end(head, n):
    dummy = Node(0)
    dummy.next = head
    fast = slow = dummy

    for _ in range(n + 1):
        if fast:
            fast = fast.next

    while fast:
        fast = fast.next
        slow = slow.next

    slow.next = slow.next.next
    return dummy.next

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

    pos = int(input("Enter the position from the end to remove: "))

    print("Original List:")
    print_list(head)

    head = remove_nth_from_end(head, pos)

    print("Updated List:")
    print_list(head)
