#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool isUnique(string str) {
    unordered_set<char> seen;
    for (char c : str) {
        if (seen.count(c)) {
            return false;
        }
        seen.insert(c);
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isUnique(str)) {
        cout << "The string contains all unique characters.\n";
    } else {
        cout << "The string does not contain all unique characters.\n";
    }

    return 0;
}
