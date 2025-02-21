import java.util.Scanner;

class Stack {
    private static final int MAX = 100;
    private int[] stack = new int[MAX];
    private int top = -1;

    public void push(int value) {
        if (top == MAX - 1) {
            System.out.println("Stack overflow!");
        } else {
            stack[++top] = value;
            System.out.println(value + " pushed into the stack.");
        }
    }

    public void pop() {
        if (top == -1) {
            System.out.println("Stack underflow!");
        } else {
            System.out.println(stack[top--] + " popped from the stack.");
        }
    }

    public void peek() {
        if (top == -1) {
            System.out.println("Stack is empty.");
        } else {
            System.out.println("Top element is: " + stack[top]);
        }
    }
}

public class StackDemo {
    public static void main(String[] args) {
        Stack stack = new Stack();
        Scanner scanner = new Scanner(System.in);

        int choice, value;
        do {
            System.out.println("\n1. Push\n2. Pop\n3. Peek\n4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    value = scanner.nextInt();
                    stack.push(value);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.peek();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 4);

        scanner.close();
    }
}
