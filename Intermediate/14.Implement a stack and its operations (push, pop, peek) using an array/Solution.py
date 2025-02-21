class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)
        print(f"{value} pushed into the stack.")

    def pop(self):
        if not self.stack:
            print("Stack underflow!")
        else:
            print(f"{self.stack.pop()} popped from the stack.")

    def peek(self):
        if not self.stack:
            print("Stack is empty.")
        else:
            print(f"Top element is: {self.stack[-1]}")

if __name__ == "__main__":
    stack = Stack()

    while True:
        print("\n1. Push\n2. Pop\n3. Peek\n4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter value to push: "))
            stack.push(value)
        elif choice == 2:
            stack.pop()
        elif choice == 3:
            stack.peek()
        elif choice == 4:
            print("Exiting...")
            break
        else:
            print("Invalid choice!")
