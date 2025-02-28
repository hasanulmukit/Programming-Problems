#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of coin denominations: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "Enter the coin denominations:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // Sort coins in descending order
    sort(coins.begin(), coins.end(), greater<int>());
    
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    
    int count = 0;
    cout << "Coins used: ";
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            count++;
            cout << coin << " ";
        }
    }
    
    if (amount != 0) {
        cout << "\nExact amount cannot be formed with the given denominations." << endl;
    } else {
        cout << "\nMinimum number of coins needed: " << count << endl;
    }
    
    return 0;
}
