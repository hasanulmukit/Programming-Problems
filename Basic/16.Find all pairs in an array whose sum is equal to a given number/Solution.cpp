#include <iostream>
#include <vector>
using namespace std;

void findPairs(vector<int>& arr, int target) {
    bool found = false;
    cout << "Pairs with sum " << target << ":\n";
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target) {
                cout << "(" << arr[i] << ", " << arr[j] << ")\n";
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No pairs found.\n";
    }
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    findPairs(arr, target);

    return 0;
}
