import java.util.*;

public class LargestNumber {
    // Custom comparator
    static class CustomComparator implements Comparator<String> {
        @Override
        public int compare(String x, String y) {
            return (y + x).compareTo(x + y); // Sort in descending order
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        String[] nums = new String[n];
        System.out.println("Enter the numbers:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.next();
        }

        Arrays.sort(nums, new CustomComparator());

        System.out.print("Largest number: ");
        for (String num : nums) {
            System.out.print(num);
        }
        System.out.println();
    }
}
