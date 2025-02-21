#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < strs[i].size() && j < prefix.size() && strs[i][j] == prefix[j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    if (!result.empty()) {
        cout << "Longest Common Prefix: " << result << endl;
    } else {
        cout << "No common prefix." << endl;
    }

    return 0;
}
