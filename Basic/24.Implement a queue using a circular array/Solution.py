class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.queue = [None] * size
        self.front = -1
        self.rear = -1

    def isFull(self):
        return (self.front == (self.rear + 1) % self.size)

    def isEmpty(self):
        return self.front == -1

    def enqueue(self, value):
        if self.isFull():
            print("Queue is full.")
            return
        if self.isEmpty():
            self.front = 0
        self.rear = (self.rear + 1) % self.size
        self.queue[self.rear] = value
        print(f"Enqueued: {value}")

    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty.")
            return
        print(f"Dequeued: {self.queue[self.front]}")
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.size

    def display(self):
        if self.isEmpty():
            print("Queue is empty.")
            return
        print("Queue:", end=" ")
        i = self.front
        while True:
            print(self.queue[i], end=" ")
            if i == self.rear:
                break
            i = (i + 1) % self.size
        print()

if __name__ == "__main__":
    size = int(input("Enter the size of the queue: "))
    q = CircularQueue(size)

    while True:
        print("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter value to enqueue: "))
            q.enqueue(value)
        elif choice == 2:
            q.dequeue()
        elif choice == 3:
            q.display()
        elif choice == 4:
            break
        else:
            print("Invalid choice.")
