import java.util.PriorityQueue;
import java.util.Scanner;

// Node class for Huffman Tree
class HuffmanNode {
    char data;
    int frequency;
    HuffmanNode left, right;

    HuffmanNode(char data, int frequency) {
        this.data = data;
        this.frequency = frequency;
        this.left = this.right = null;
    }
}

// Comparator class for Priority Queue
class HuffmanComparator implements java.util.Comparator<HuffmanNode> {
    public int compare(HuffmanNode a, HuffmanNode b) {
        return a.frequency - b.frequency;
    }
}

public class HuffmanEncoding {
    // Print the Huffman codes
    public static void printCodes(HuffmanNode root, String code) {
        if (root == null) {
            return;
        }

        // If it’s a leaf node, print the character and its code
        if (root.left == null && root.right == null && Character.isLetter(root.data)) {
            System.out.println(root.data + ": " + code);
        }

        // Traverse the left and right children
        printCodes(root.left, code + "0");
        printCodes(root.right, code + "1");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of characters
        System.out.print("Enter the number of characters: ");
        int n = scanner.nextInt();

        char[] data = new char[n];
        int[] freq = new int[n];

        // Input the characters and their frequencies
        System.out.println("Enter the characters and their frequencies:");
        for (int i = 0; i < n; i++) {
            System.out.print("Character " + (i + 1) + ": ");
            data[i] = scanner.next().charAt(0);
            System.out.print("Frequency " + (i + 1) + ": ");
            freq[i] = scanner.nextInt();
        }

        // Create a priority queue for Huffman tree nodes
        PriorityQueue<HuffmanNode> queue = new PriorityQueue<>(n, new HuffmanComparator());

        // Create a leaf node for each character and add it to the priority queue
        for (int i = 0; i < n; i++) {
            queue.add(new HuffmanNode(data[i], freq[i]));
        }

        // Build the Huffman tree
        while (queue.size() > 1) {
            HuffmanNode left = queue.poll();
            HuffmanNode right = queue.poll();

            // Combine the two smallest nodes
            HuffmanNode newNode = new HuffmanNode('$', left.frequency + right.frequency);
            newNode.left = left;
            newNode.right = right;

            queue.add(newNode);
        }

        // Root of the Huffman tree
        HuffmanNode root = queue.poll();

        // Print the Huffman codes
        System.out.println("Huffman Codes:");
        printCodes(root, "");
    }
}
