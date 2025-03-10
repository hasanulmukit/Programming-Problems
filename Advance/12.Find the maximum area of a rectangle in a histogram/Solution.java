import java.util.Scanner;
import java.util.Stack;

public class HistogramMaxArea {
    public static int maxRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0, n = heights.length;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!stack.isEmpty() && currHeight < heights[stack.peek()]) {
                int h = heights[stack.pop()];
                int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxArea = Math.max(maxArea, h * width);
            }
            stack.push(i);
        }
        return maxArea;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of bars in the histogram: ");
        int n = sc.nextInt();

        int[] heights = new int[n];
        System.out.print("Enter the heights of the bars: ");
        for (int i = 0; i < n; i++) {
            heights[i] = sc.nextInt();
        }

        int result = maxRectangleArea(heights);
        System.out.println("Maximum area of rectangle: " + result);
    }
}
