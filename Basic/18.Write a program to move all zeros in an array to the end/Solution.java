import java.util.Scanner;

public class MoveZeros {
    public static void moveZerosToEnd(int[] arr) {
        int j = 0; // Points to the next position for a non-zero element

        // Traverse the array
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                // Swap non-zero element with the element at index j
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.print("Enter " + n + " elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        moveZerosToEnd(arr);

        System.out.print("Array after moving zeros to the end: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
