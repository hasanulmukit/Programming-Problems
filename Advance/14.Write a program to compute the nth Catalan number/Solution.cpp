#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long long catalanNumber(int n) {
    unsigned long long numerator = factorial(2 * n);
    unsigned long long denominator = factorial(n + 1) * factorial(n);
    return numerator / denominator;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "th Catalan number is: " << catalanNumber(n) << endl;
    return 0;
}
