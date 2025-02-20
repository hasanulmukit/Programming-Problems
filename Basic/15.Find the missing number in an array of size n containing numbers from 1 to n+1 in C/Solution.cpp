#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& arr, int n) {
    int total = (n + 1) * (n + 2) / 2; // Sum of 1 to n+1
    for (int num : arr) {
        total -= num; // Subtract array elements from total
    }
    return total;
}

int main() {
    int n;
    cout << "Enter the size of the array (n): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(arr, n);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}
