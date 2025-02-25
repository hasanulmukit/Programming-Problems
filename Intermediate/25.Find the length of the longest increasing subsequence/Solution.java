import java.util.Scanner;

public class LIS {
    public static int longestIncreasingSubsequence(int[] arr, int n) {
        int[] lis = new int[n];
        for (int i = 0; i < n; i++)
            lis[i] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }

        int max = 0;
        for (int i = 0; i < n; i++) {
            if (lis[i] > max)
                max = lis[i];
        }

        return max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        int result = longestIncreasingSubsequence(arr, n);
        System.out.println("Length of Longest Increasing Subsequence: " + result);
    }
}
