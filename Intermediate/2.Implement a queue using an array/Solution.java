import java.util.Scanner;

class Queue {
    private int front, rear;
    private int[] queue;
    private static final int SIZE = 100;

    public Queue() {
        front = -1;
        rear = -1;
        queue = new int[SIZE];
    }

    public void enqueue(int value) {
        if (rear == SIZE - 1) {
            System.out.println("Queue is full!");
        } else {
            if (front == -1) front = 0;
            queue[++rear] = value;
            System.out.println("Inserted: " + value);
        }
    }

    public void dequeue() {
        if (front == -1 || front > rear) {
            System.out.println("Queue is empty!");
        } else {
            System.out.println("Removed: " + queue[front++]);
            if (front > rear) front = rear = -1;
        }
    }

    public void display() {
        if (front == -1) {
            System.out.println("Queue is empty!");
        } else {
            System.out.print("Queue elements: ");
            for (int i = front; i <= rear; i++) {
                System.out.print(queue[i] + " ");
            }
            System.out.println();
        }
    }
}

public class QueueArray {
    public static void main(String[] args) {
        Queue q = new Queue();
        Scanner scanner = new Scanner(System.in);
        int choice, value;

        while (true) {
            System.out.println("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to insert: ");
                    value = scanner.nextInt();
                    q.enqueue(value);
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}
