import java.util.Scanner;

public class RemoveDuplicates {
    public static int removeDuplicates(int[] arr, int n) {
        if (n == 0) return 0;
        int j = 0; // Index for the next unique element
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[j]) {
                j++;
                arr[j] = arr[i];
            }
        }
        return j + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the sorted array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.print("Enter " + n + " elements of the sorted array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int newSize = removeDuplicates(arr, n);
        System.out.print("Array after removing duplicates: ");
        for (int i = 0; i < newSize; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
