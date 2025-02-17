#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(const vector<int> &arr1, const vector<int> &arr2, vector<int> &merged) {
    int i = 0, j = 0;

    // Merge both arrays
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }

    // Copy remaining elements of arr1
    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }

    // Copy remaining elements of arr2
    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }
}

int main() {
    int n1, n2;

    cout << "Enter the number of elements in the first sorted array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter the elements of the first sorted array:\n";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements in the second sorted array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter the elements of the second sorted array:\n";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    vector<int> merged;
    mergeSortedArrays(arr1, arr2, merged);

    cout << "Merged sorted array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
