#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compareItems(const Item &a, const Item &b) {
    // Sort in descending order of ratio
    return a.ratio > b.ratio;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double) items[i].value / items[i].weight;
    }
    
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    
    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compareItems);
    
    double totalValue = 0.0;
    vector<double> fraction(n, 0.0);
    
    // Greedy selection: take full item if possible, else take fraction
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            fraction[i] = 1.0;
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            fraction[i] = (double) capacity / items[i].weight;
            totalValue += items[i].value * fraction[i];
            capacity = 0;
        }
    }
    
    cout << "\nMaximum value achievable: " << totalValue << endl;
    cout << "Item fractions taken:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": " << fraction[i] * 100 << "%" << endl;
    }
    
    return 0;
}
