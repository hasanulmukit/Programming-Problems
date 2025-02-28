import java.util.Arrays;
import java.util.Scanner;

class FractionalKnapsack {
    // Item class to store weight, value, and ratio
    static class Item implements Comparable<Item> {
        int weight, value;
        double ratio;

        Item(int value, int weight) {
            this.weight = weight;
            this.value = value;
            this.ratio = (double) value / weight;
        }

        @Override
        public int compareTo(Item other) {
            return Double.compare(other.ratio, this.ratio);
        }
    }

    // Function to solve the fractional knapsack problem
    public static void fractionalKnapsack(Item[] items, int capacity) {
        Arrays.sort(items);

        double totalValue = 0.0;
        System.out.println("Selected items (weight taken):");
        for (Item item : items) {
            if (capacity >= item.weight) {
                totalValue += item.value;
                capacity -= item.weight;
                System.out.println("Item with value " + item.value + " and weight " + item.weight + ": Full");
            } else {
                totalValue += item.value * ((double) capacity / item.weight);
                System.out.println("Item with value " + item.value + " and weight " + item.weight + ": " + capacity);
                break;
            }
        }

        System.out.println("Maximum value: " + totalValue);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of items and knapsack capacity
        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();
        System.out.print("Enter the capacity of the knapsack: ");
        int capacity = scanner.nextInt();

        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter value and weight for item " + (i + 1) + ": ");
            int value = scanner.nextInt();
            int weight = scanner.nextInt();
            items[i] = new Item(value, weight);
        }

        fractionalKnapsack(items, capacity);
    }
}
