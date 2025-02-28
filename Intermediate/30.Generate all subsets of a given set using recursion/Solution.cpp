#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate subsets
void generateSubsets(const vector<int>& set, int index, vector<int>& currentSubset) {
    // Base case: if we've processed all elements, print the current subset.
    if (index == set.size()) {
        cout << "{ ";
        for (int num : currentSubset)
            cout << num << " ";
        cout << "}" << endl;
        return;
    }

    // Recurse without including the current element.
    generateSubsets(set, index + 1, currentSubset);

    // Include the current element.
    currentSubset.push_back(set[index]);
    generateSubsets(set, index + 1, currentSubset);

    // Backtrack: remove the last element before returning.
    currentSubset.pop_back();
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    vector<int> currentSubset;
    cout << "\nAll subsets:" << endl;
    generateSubsets(set, 0, currentSubset);

    return 0;
}
