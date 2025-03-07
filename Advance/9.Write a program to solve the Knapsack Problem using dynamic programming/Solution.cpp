#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter the weights and values of the items:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weights[i];
        cout << "Item " << i + 1 << " - Value: ";
        cin >> values[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value in knapsack: " << knapsack(W, weights, values, n) << endl;

    return 0;
}
