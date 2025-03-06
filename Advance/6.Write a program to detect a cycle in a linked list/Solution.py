class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def detect_cycle(head):
    slow, fast = head, head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

if __name__ == "__main__":
    n = int(input("Enter the number of nodes: "))
    head = None
    tail = None

    for i in range(n):
        val = int(input(f"Enter value for node {i + 1}: "))
        new_node = Node(val)
        if head is None:
            head = new_node
        else:
            tail.next = new_node
        tail = new_node

    pos = int(input("Enter the position to create a cycle (0 for no cycle): "))
    if pos > 0:
        temp = head
        for _ in range(pos - 1):
            temp = temp.next
        tail.next = temp

    if detect_cycle(head):
        print("Cycle detected in the linked list.")
    else:
        print("No cycle detected in the linked list.")
