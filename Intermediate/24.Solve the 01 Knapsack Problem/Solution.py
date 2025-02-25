def knapsack(n, W, weights, values):
    dp = [[0] * (W + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(W + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][W]


if __name__ == "__main__":
    n = int(input("Enter the number of items: "))
    weights = list(map(int, input("Enter the weights of the items: ").split()))
    values = list(map(int, input("Enter the values of the items: ").split()))
    W = int(input("Enter the maximum capacity of the knapsack: "))

    print("Maximum value:", knapsack(n, W, weights, values))
