#include <iostream>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    int original = num, reversed = 0, remainder;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    return original == reversed; // Return true if original equals reversed
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << "The number is a palindrome." << endl;
    } else {
        cout << "The number is not a palindrome." << endl;
    }

    return 0;
}
