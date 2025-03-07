def knapsack(W, weights, values, n):
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][W]


if __name__ == "__main__":
    n = int(input("Enter the number of items: "))

    weights = []
    values = []

    print("Enter the weights and values of the items:")
    for i in range(n):
        weight = int(input(f"Item {i + 1} - Weight: "))
        value = int(input(f"Item {i + 1} - Value: "))
        weights.append(weight)
        values.append(value)

    W = int(input("Enter the capacity of the knapsack: "))

    print(f"Maximum value in knapsack: {knapsack(W, weights, values, n)}")
