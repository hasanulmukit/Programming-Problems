#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Custom comparator function
bool compare(string x, string y) {
    return x + y > y + x;
}

// Function to find the largest number
void findLargestNumber(vector<string> &nums) {
    sort(nums.begin(), nums.end(), compare);

    cout << "Largest number: ";
    for (string num : nums) {
        cout << num;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<string> nums(n);
    cout << "Enter the numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    findLargestNumber(nums);
    return 0;
}
