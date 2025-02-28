import java.util.Scanner;

public class Subsets {
    public static void generateSubsets(char[] set, String subset, int index) {
        if (index == set.length) {
            System.out.println("{" + subset + "}");
            return;
        }

        // Exclude the current element
        generateSubsets(set, subset, index + 1);

        // Include the current element
        generateSubsets(set, subset + set[index], index + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the set: ");
        int n = scanner.nextInt();
        char[] set = new char[n];

        System.out.print("Enter the elements of the set: ");
        for (int i = 0; i < n; i++) {
            set[i] = scanner.next().charAt(0);
        }

        System.out.println("The subsets are:");
        generateSubsets(set, "", 0);

        scanner.close();
    }
}
