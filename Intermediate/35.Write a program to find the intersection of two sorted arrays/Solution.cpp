#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter the number of elements in the first sorted array: ";
    cin >> n1;
    
    vector<int> arr1(n1);
    cout << "Enter " << n1 << " sorted elements for the first array (space-separated): ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    
    cout << "Enter the number of elements in the second sorted array: ";
    cin >> n2;
    
    vector<int> arr2(n2);
    cout << "Enter " << n2 << " sorted elements for the second array (space-separated): ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    cout << "Intersection of the two arrays: ";
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    cout << endl;
    return 0;
}
