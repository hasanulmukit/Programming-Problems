import java.util.Scanner;
import java.util.Stack;

class MinStack {
    private Stack<Integer> mainStack = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();

    public void push(int value) {
        mainStack.push(value);
        if (minStack.isEmpty() || value <= minStack.peek()) {
            minStack.push(value);
        }
        System.out.println("Pushed: " + value);
    }

    public void pop() {
        if (mainStack.isEmpty()) {
            System.out.println("Stack underflow.");
            return;
        }
        if (mainStack.peek().equals(minStack.peek())) {
            minStack.pop();
        }
        System.out.println("Popped: " + mainStack.pop());
    }

    public int getMin() {
        if (minStack.isEmpty()) {
            System.out.println("Stack is empty.");
            return Integer.MAX_VALUE;
        }
        return minStack.peek();
    }
}

public class MinStackDemo {
    public static void main(String[] args) {
        MinStack ms = new MinStack();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n1. Push\n2. Pop\n3. Get Minimum\n4. Exit\nEnter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    int value = sc.nextInt();
                    ms.push(value);
                    break;
                case 2:
                    ms.pop();
                    break;
                case 3:
                    System.out.println("Minimum: " + ms.getMin());
                    break;
                case 4:
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
