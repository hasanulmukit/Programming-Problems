#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int>& arr) {
    int count = 0, candidate = -1;

    // Finding candidate
    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Verifying candidate
    count = 0;
    for (int num : arr) {
        if (num == candidate)
            count++;
    }
    return (count > arr.size() / 2) ? candidate : -1;
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

    int result = findMajorityElement(arr);
    if (result != -1)
        cout << "The majority element is: " << result << endl;
    else
        cout << "No majority element found." << endl;

    return 0;
}
