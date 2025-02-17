#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    int start = 0, end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false; // Not a palindrome
        }
        start++;
        end--;
    }
    return true; // Palindrome
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
