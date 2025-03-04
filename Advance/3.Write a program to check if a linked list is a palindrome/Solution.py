class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        if not self.head:
            self.head = Node(data)
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = Node(data)

    def is_palindrome(self):
        stack = []
        temp = self.head
        while temp:
            stack.append(temp.data)
            temp = temp.next

        temp = self.head
        while temp:
            if temp.data != stack.pop():
                return False
            temp = temp.next
        return True

if __name__ == "__main__":
    ll = LinkedList()
    n = int(input("Enter number of elements: "))

    print("Enter elements:")
    for _ in range(n):
        ll.append(int(input()))

    if ll.is_palindrome():
        print("The linked list is a palindrome.")
    else:
        print("The linked list is not a palindrome.")
