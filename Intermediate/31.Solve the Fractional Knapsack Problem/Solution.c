#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

// Comparator function to sort items by value-to-weight ratio in descending order
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

// Function to solve the fractional knapsack problem
void fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    printf("Selected items (weight taken):\n");
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
            printf("Item %d: %d\n", i + 1, items[i].weight);
        } else {
            totalValue += items[i].value * ((float)capacity / items[i].weight);
            printf("Item %d: %d\n", i + 1, capacity);
            break;
        }
    }

    printf("Maximum value: %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    // Input the number of items and knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    fractionalKnapsack(items, n, capacity);

    return 0;
}
