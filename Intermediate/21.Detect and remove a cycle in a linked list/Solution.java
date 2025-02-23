import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class DetectRemoveCycle {

    public static boolean detectAndRemoveCycle(Node head) {
        Node slow = head, fast = head;

        // Detect Cycle
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) break;
        }

        if (fast == null || fast.next == null) return false; // No cycle

        // Remove Cycle
        slow = head;
        while (slow.next != fast.next) {
            slow = slow.next;
            fast = fast.next;
        }

        fast.next = null; // Break the cycle
        return true;
    }

    public static void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of nodes: ");
        int n = scanner.nextInt();

        Node head = null, tail = null, cycleNode = null;
        for (int i = 0; i < n; i++) {
            System.out.print("Enter value for node " + (i + 1) + ": ");
            int value = scanner.nextInt();
            Node newNode = new Node(value);
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }

            if (i == 2) cycleNode = newNode; // Optional to create a cycle
        }

        System.out.print("Enter the position to create a cycle (0 for no cycle): ");
        int cyclePosition = scanner.nextInt();
        if (cyclePosition > 0) {
            tail.next = cycleNode;
        }

        if (detectAndRemoveCycle(head)) {
            System.out.println("Cycle detected and removed.");
        } else {
            System.out.println("No cycle detected.");
        }

        System.out.println("Updated List:");
        printList(head);
        scanner.close();
    }
}
