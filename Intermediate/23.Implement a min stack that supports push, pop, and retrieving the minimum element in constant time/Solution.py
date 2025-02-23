class MinStack:
    def __init__(self):
        self.main_stack = []
        self.min_stack = []

    def push(self, value):
        self.main_stack.append(value)
        if not self.min_stack or value <= self.min_stack[-1]:
            self.min_stack.append(value)
        print(f"Pushed: {value}")

    def pop(self):
        if not self.main_stack:
            print("Stack underflow.")
            return
        if self.main_stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        print(f"Popped: {self.main_stack.pop()}")

    def get_min(self):
        if not self.min_stack:
            print("Stack is empty.")
            return float('inf')
        return self.min_stack[-1]


if __name__ == "__main__":
    ms = MinStack()
    while True:
        print("\n1. Push\n2. Pop\n3. Get Minimum\n4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter value to push: "))
            ms.push(value)
        elif choice == 2:
            ms.pop()
        elif choice == 3:
            print(f"Minimum: {ms.get_min()}")
        elif choice == 4:
            break
        else:
            print("Invalid choice.")
