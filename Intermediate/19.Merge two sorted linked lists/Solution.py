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

def merge_sorted_lists(l1, l2):
    if not l1:
        return l2
    if not l2:
        return l1

    if l1.data < l2.data:
        l1.next = merge_sorted_lists(l1.next, l2)
        return l1
    else:
        l2.next = merge_sorted_lists(l1, l2.next)
        return l2

if __name__ == "__main__":
    n1 = int(input("Enter the number of nodes in the first sorted list: "))
    head1 = None
    tail1 = None

    for i in range(n1):
        value = int(input(f"Enter value for node {i + 1}: "))
        new_node = Node(value)
        if not head1:
            head1 = tail1 = new_node
        else:
            tail1.next = new_node
            tail1 = new_node

    n2 = int(input("Enter the number of nodes in the second sorted list: "))
    head2 = None
    tail2 = None

    for i in range(n2):
        value = int(input(f"Enter value for node {i + 1}: "))
        new_node = Node(value)
        if not head2:
            head2 = tail2 = new_node
        else:
            tail2.next = new_node
            tail2 = new_node

    print("First List:")
    print_list(head1)
    print("Second List:")
    print_list(head2)

    merged_list = merge_sorted_lists(head1, head2)
    print("Merged List:")
    print_list(merged_list)
