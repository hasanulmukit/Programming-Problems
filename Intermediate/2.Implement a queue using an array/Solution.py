class Queue:
    def __init__(self, size=100):
        self.queue = [None] * size
        self.front = -1
        self.rear = -1
        self.size = size

    def enqueue(self, value):
        if self.rear == self.size - 1:
            print("Queue is full!")
        else:
            if self.front == -1:
                self.front = 0
            self.rear += 1
            self.queue[self.rear] = value
            print(f"Inserted: {value}")

    def dequeue(self):
        if self.front == -1 or self.front > self.rear:
            print("Queue is empty!")
        else:
            print(f"Removed: {self.queue[self.front]}")
            self.front += 1
            if self.front > self.rear:
                self.front = self.rear = -1

    def display(self):
        if self.front == -1:
            print("Queue is empty!")
        else:
            print("Queue elements:", self.queue[self.front : self.rear + 1])

# Main program
queue = Queue()
while True:
    print("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        value = int(input("Enter value to insert: "))
        queue.enqueue(value)
    elif choice == 2:
        queue.dequeue()
    elif choice == 3:
        queue.display()
    elif choice == 4:
        break
    else:
        print("Invalid choice!")
