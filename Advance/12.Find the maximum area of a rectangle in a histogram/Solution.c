#include <stdio.h>
#include <stdlib.h>

int maxRectangleArea(int heights[], int n) {
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];
        for (int j = i; j < n; j++) {
            if (heights[j] < minHeight) {
                minHeight = heights[j];
            }
            int area = minHeight * (j - i + 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    return maxArea;
}

int main() {
    int n;
    printf("Enter the number of bars in the histogram: ");
    scanf("%d", &n);

    int heights[n];
    printf("Enter the heights of the bars: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int result = maxRectangleArea(heights, n);
    printf("Maximum area of rectangle: %d\n", result);
    return 0;
}
