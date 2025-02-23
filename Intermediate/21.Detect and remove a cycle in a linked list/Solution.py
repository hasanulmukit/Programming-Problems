class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def detect_and_remove_cycle(head):
    slow, fast = head, head

    # Detect Cycle
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break

    if not fast or not fast.next:
        return False  # No cycle

    # Remove Cycle
    slow = head
    while slow.next != fast.next:
        slow = slow.next
        fast = fast.next

    fast.next = None  # Break the cycle
    return True

def print_list(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("NULL")

if __name__ == "__main__":
    n = int(input("Enter the number of nodes: "))
    head = None
    tail = None
    nodes = []

    for i in range(n):
        value = int(input(f"Enter value for node {i + 1}: "))
        new_node = Node(value)
        if not head:
            head = tail = new_node
        else:
            tail.next = new_node
            tail = new_node
        nodes.append(new_node)

    cycle_position = int(input("Enter the position to create a cycle (0 for no cycle): "))
    if cycle_position > 0:
        tail.next = nodes[cycle_position - 1]

    if detect_and_remove_cycle(head):
        print("Cycle detected and removed.")
    else:
        print("No cycle detected.")

    print("Updated List:")
    print_list(head)
