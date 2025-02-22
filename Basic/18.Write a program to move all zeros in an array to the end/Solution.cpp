#include <iostream>
#include <vector>
using namespace std;

void moveZerosToEnd(vector<int>& arr) {
    int j = 0; // Points to the next position for a non-zero element

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveZerosToEnd(arr);

    cout << "Array after moving zeros to the end: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
