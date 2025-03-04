import java.util.Stack;
import java.util.Scanner;

class Queue {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();

    void enqueue(int value) {
        s1.push(value);
    }

    int dequeue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        if (s2.isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        return s2.pop();
    }
}

public class QueueUsingTwoStacks {
    public static void main(String[] args) {
        Queue q = new Queue();
        Scanner scanner = new Scanner(System.in);
        int choice, value;

        do {
            System.out.println("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to enqueue: ");
                    value = scanner.nextInt();
                    q.enqueue(value);
                    break;
                case 2:
                    value = q.dequeue();
                    if (value != -1)
                        System.out.println("Dequeued value: " + value);
                    break;
                case 3:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 3);

        scanner.close();
    }
}
