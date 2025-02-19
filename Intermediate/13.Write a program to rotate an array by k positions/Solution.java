import java.util.Scanner;

public class RotateArray {
    public static void rotateArray(int[] arr, int k) {
        int n = arr.length;
        k = k % n;
        int[] temp = new int[n];

        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = arr[i];
        }

        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the number of positions to rotate: ");
        int k = scanner.nextInt();

        rotateArray(arr, k);

        System.out.println("Rotated array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
