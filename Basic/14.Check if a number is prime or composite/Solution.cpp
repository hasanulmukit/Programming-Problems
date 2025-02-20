#include <iostream>
using namespace std;

int main() {
    int num;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1) {
        cout << "The number is neither prime nor composite." << endl;
    } else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << "The number is prime." << endl;
        } else {
            cout << "The number is composite." << endl;
        }
    }

    return 0;
}
