import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class DetectCycle {
    static boolean detectCycle(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();

        Node head = null, tail = null;
        for (int i = 0; i < n; i++) {
            System.out.print("Enter value for node " + (i + 1) + ": ");
            int val = scanner.nextInt();
            Node newNode = new Node(val);
            if (head == null) {
                head = newNode;
            } else {
                tail.next = newNode;
            }
            tail = newNode;
        }

        System.out.print("Enter the position to create a cycle (0 for no cycle): ");
        int pos = scanner.nextInt();
        if (pos > 0) {
            Node temp = head;
            for (int i = 1; i < pos; i++) {
                temp = temp.next;
            }
            tail.next = temp;
        }

        if (detectCycle(head))
            System.out.println("Cycle detected in the linked list.");
        else
            System.out.println("No cycle detected in the linked list.");

        scanner.close();
    }
}
