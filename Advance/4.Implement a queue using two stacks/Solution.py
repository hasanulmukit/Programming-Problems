class Queue:
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def enqueue(self, value):
        self.s1.append(value)

    def dequeue(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        if not self.s2:
            print("Queue is empty")
            return -1
        return self.s2.pop()

if __name__ == "__main__":
    q = Queue()
    while True:
        print("\n1. Enqueue\n2. Dequeue\n3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter value to enqueue: "))
            q.enqueue(value)
        elif choice == 2:
            value = q.dequeue()
            if value != -1:
                print(f"Dequeued value: {value}")
        elif choice == 3:
            print("Exiting...")
            break
        else:
            print("Invalid choice")
