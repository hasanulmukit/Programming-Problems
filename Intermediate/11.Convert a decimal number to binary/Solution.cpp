#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n == 0) {
        cout << "0";
        return;
    }

    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }

    cout << binary;
}

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;

    cout << "Binary representation: ";
    decimalToBinary(num);
    cout << endl;

    return 0;
}
