import java.util.Scanner;

public class MajorityElement {
    public static int findMajorityElement(int[] arr, int n) {
        int count = 0, candidate = -1;

        // Finding candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Verifying candidate
        count = 0;
        for (int num : arr) {
            if (num == candidate)
                count++;
        }
        return (count > n / 2) ? candidate : -1;
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

        int result = findMajorityElement(arr, n);
        if (result != -1)
            System.out.println("The majority element is: " + result);
        else
            System.out.println("No majority element found.");
    }
}
