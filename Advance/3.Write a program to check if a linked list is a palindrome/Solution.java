import java.util.*;

class Node {
    int data;
    Node next;
    Node(int val) {
        data = val;
        next = null;
    }
}

public class PalindromeLinkedList {
    public static void append(Node head, int data) {
        Node newNode = new Node(data);
        Node temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
    }

    public static boolean isPalindrome(Node head) {
        Stack<Integer> stack = new Stack<>();
        Node temp = head;

        while (temp != null) {
            stack.push(temp.data);
            temp = temp.next;
        }

        temp = head;
        while (temp != null) {
            if (temp.data != stack.pop()) return false;
            temp = temp.next;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();

        System.out.print("Enter elements:\n");
        int val = scanner.nextInt();
        Node head = new Node(val);

        for (int i = 1; i < n; i++) {
            val = scanner.nextInt();
            append(head, val);
        }

        if (isPalindrome(head)) {
            System.out.println("The linked list is a palindrome.");
        } else {
            System.out.println("The linked list is not a palindrome.");
        }
        scanner.close();
    }
}
