#include <iostream>
#include <vector>
using namespace std;

void findDuplicates(vector<int> &arr) {
    cout << "Duplicate elements: ";
    bool found = false;

    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                found = true;
                break; // Avoid printing the same duplicate multiple times
            }
        }
    }

    if (!found) {
        cout << "None";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findDuplicates(arr);

    return 0;
}
