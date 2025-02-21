#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

char firstNonRepeatingChar(const string& str) {
    unordered_map<char, int> count;

    for (char c : str) {
        count[c]++;
    }

    for (char c : str) {
        if (count[c] == 1) {
            return c;
        }
    }
    return '\0';
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    char result = firstNonRepeatingChar(str);
    if (result != '\0') {
        cout << "The first non-repeating character is: " << result << endl;
    } else {
        cout << "No non-repeating character found.\n";
    }

    return 0;
}
