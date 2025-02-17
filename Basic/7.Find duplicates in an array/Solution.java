import java.util.Scanner;

public class FindDuplicates {

    static void findDuplicates(int[] arr) {
        System.out.print("Duplicate elements: ");
        boolean found = false;

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] == arr[j]) {
                    System.out.print(arr[i] + " ");
                    found = true;
                    break; // Avoid printing the same duplicate multiple times
                }
            }
        }

        if (!found) {
            System.out.print("None");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        findDuplicates(arr);

        scanner.close();
    }
}
