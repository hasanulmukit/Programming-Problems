#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num != 0) {
        sum += num % 10; // Get the last digit
        num /= 10;       // Remove the last digit
    }

    cout << "Sum of the digits: " << sum << endl;

    return 0;
}
