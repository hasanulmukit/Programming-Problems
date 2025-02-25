def coin_change(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0

    for i in range(1, amount + 1):
        for coin in coins:
            if i >= coin:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return -1 if dp[amount] == float('inf') else dp[amount]

if __name__ == "__main__":
    n = int(input("Enter the number of coin types: "))
    coins = list(map(int, input("Enter the coin denominations: ").split()))
    amount = int(input("Enter the amount: "))

    result = coin_change(coins, amount)
    if result == -1:
        print("No solution exists.")
    else:
        print("Minimum coins needed:", result)
