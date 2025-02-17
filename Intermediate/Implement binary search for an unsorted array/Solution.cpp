#include <iostream>
#include <algorithm>
using namespace std;

// Binary Search function
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main() {
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the unsorted elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element: ";
    cin >> target;

    sort(arr, arr + n); // Sort the array

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index " << result << " (after sorting)." << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
