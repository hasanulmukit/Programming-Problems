import java.util.LinkedList;
import java.util.Scanner;

class HashMap {
    static class Node {
        int key, value;

        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private static final int TABLE_SIZE = 10;
    private LinkedList<Node>[] table;

    @SuppressWarnings("unchecked")
    public HashMap() {
        table = new LinkedList[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = new LinkedList<>();
        }
    }

    private int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    public void insert(int key, int value) {
        int index = hashFunction(key);
        for (Node node : table[index]) {
            if (node.key == key) {
                node.value = value; // Update value if key exists
                return;
            }
        }
        table[index].add(new Node(key, value));
    }

    public Integer get(int key) {
        int index = hashFunction(key);
        for (Node node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return null; // Key not found
    }

    public void delete(int key) {
        int index = hashFunction(key);
        table[index].removeIf(node -> node.key == key);
    }

    public void printHashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            System.out.print("Index " + i + ": ");
            for (Node node : table[i]) {
                System.out.print("(" + node.key + " -> " + node.value + ") ");
            }
            System.out.println();
        }
    }
}

public class HashMapDemo {
    public static void main(String[] args) {
        HashMap map = new HashMap();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n1. Insert\n2. Get\n3. Delete\n4. Print\n5. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter key and value: ");
                    int key = scanner.nextInt();
                    int value = scanner.nextInt();
                    map.insert(key, value);
                    break;
                case 2:
                    System.out.print("Enter key: ");
                    key = scanner.nextInt();
                    Integer result = map.get(key);
                    if (result == null) {
                        System.out.println("Key not found.");
                    } else {
                        System.out.println("Value: " + result);
                    }
                    break;
                case 3:
                    System.out.print("Enter key to delete: ");
                    key = scanner.nextInt();
                    map.delete(key);
                    break;
                case 4:
                    map.printHashMap();
                    break;
                case 5:
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
