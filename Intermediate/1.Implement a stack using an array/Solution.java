import java.util.Scanner;

public class StackUsingArray {
    static final int MAX = 100;
    static int[] stack = new int[MAX];
    static int top = -1;

    static void push() {
        if (top == MAX - 1) {
            System.out.println("Stack overflow!");
            return;
        }
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter value to push: ");
        int val = scanner.nextInt();
        stack[++top] = val;
        System.out.println(val + " pushed onto stack.");
    }

    static void pop() {
        if (top == -1) {
            System.out.println("Stack underflow!");
            return;
        }
        System.out.println(stack[top--] + " popped from stack.");
    }

    static void display() {
        if (top == -1) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.println("Stack elements:");
        for (int i = top; i >= 0; i--) {
            System.out.println(stack[i]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n1. Push\n2. Pop\n3. Display\n4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1: push(); break;
                case 2: pop(); break;
                case 3: display(); break;
                case 4: return;
                default: System.out.println("Invalid choice!");
            }
        }
    }
}
