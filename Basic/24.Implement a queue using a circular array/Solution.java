import java.util.Scanner;

class CircularQueue {
    private int[] arr;
    private int front, rear, size;

    public CircularQueue(int size) {
        this.size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    public boolean isFull() {
        return (front == (rear + 1) % size);
    }

    public boolean isEmpty() {
        return (front == -1);
    }

    public void enqueue(int value) {
        if (isFull()) {
            System.out.println("Queue is full.");
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        System.out.println("Enqueued: " + value);
    }

    public void dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty.");
            return;
        }
        System.out.println("Dequeued: " + arr[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Queue is empty.");
            return;
        }
        System.out.print("Queue: ");
        int i = front;
        while (true) {
            System.out.print(arr[i] + " ");
            if (i == rear) break;
            i = (i + 1) % size;
        }
        System.out.println();
    }
}

public class CircularQueueDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the queue: ");
        int size = sc.nextInt();

        CircularQueue q = new CircularQueue(size);

        while (true) {
            System.out.println("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to enqueue: ");
                    int value = sc.nextInt();
                    q.enqueue(value);
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
