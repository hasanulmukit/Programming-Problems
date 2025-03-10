def maxRectangleArea(heights):
    stack = []
    max_area = 0
    n = len(heights)

    for i in range(n + 1):
        curr_height = heights[i] if i < n else 0
        while stack and curr_height < heights[stack[-1]]:
            h = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, h * width)
        stack.append(i)

    return max_area


if __name__ == "__main__":
    n = int(input("Enter the number of bars in the histogram: "))
    heights = list(map(int, input("Enter the heights of the bars: ").split()))

    result = maxRectangleArea(heights)
    print(f"Maximum area of rectangle: {result}")
