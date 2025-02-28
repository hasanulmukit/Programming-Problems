def fractional_knapsack(items, capacity):
    # Each item is a tuple (value, weight)
    # Compute ratio and sort items in descending order of ratio
    items = sorted(items, key=lambda x: x[0] / x[1], reverse=True)
    
    total_value = 0.0
    fractions = []
    
    for value, weight in items:
        if capacity == 0:
            fractions.append(0)
            continue
        if weight <= capacity:
            fractions.append(1)
            total_value += value
            capacity -= weight
        else:
            frac = capacity / weight
            fractions.append(frac)
            total_value += value * frac
            capacity = 0
    return total_value, fractions

if __name__ == "__main__":
    n = int(input("Enter the number of items: "))
    items = []
    print("Enter the value and weight for each item (separated by space):")
    for i in range(n):
        value, weight = map(int, input(f"Item {i+1}: ").split())
        items.append((value, weight))
    
    capacity = int(input("Enter the capacity of the knapsack: "))
    
    total_value, fractions = fractional_knapsack(items, capacity)
    print(f"\nMaximum value achievable: {total_value}")
    print("Item fractions taken:")
    for i, frac in enumerate(fractions):
        print(f"Item {i+1}: {frac * 100:.2f}%")
