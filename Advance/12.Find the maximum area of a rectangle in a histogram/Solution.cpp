#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0, n = heights.size();

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    int n;
    cout << "Enter the number of bars in the histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int result = maxRectangleArea(heights);
    cout << "Maximum area of rectangle: " << result << endl;
    return 0;
}
