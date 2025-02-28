def min_coins(coins, amount):
    # Sort coins in descending order
    coins.sort(reverse=True)
    count = 0
    used_coins = []
    
    for coin in coins:
        while amount >= coin:
            amount -= coin
            count += 1
            used_coins.append(coin)
    
    return count, used_coins, amount

if __name__ == "__main__":
    n = int(input("Enter the number of coin denominations: "))
    coins = []
    print("Enter the coin denominations:")
    for _ in range(n):
        coins.append(int(input()))
    
    amount = int(input("Enter the amount: "))
    count, used_coins, remainder = min_coins(coins, amount)
    
    if remainder != 0:
        print("Exact amount cannot be formed with the given denominations.")
    else:
        print("Coins used:", used_coins)
        print("Minimum number of coins needed:", count)
