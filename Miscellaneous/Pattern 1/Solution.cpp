#include <iostream>
#include <iomanip>
using namespace std;

void printPattern(int n) {
    int num = 1;
    for(int i = 1; i <= n; i++) {
        // Print leading spaces
        for(int space = 1; space <= n - i; space++) {
            cout << "   ";
        }
        
        // Print numbers
        if(i % 2 == 1) {  // Odd rows: left to right
            for(int j = 1; j <= n; j++) {
                cout << setw(2) << num++ << " ";
            }
        } else {  // Even rows: right to left
            int temp = num + n - 1;
            for(int j = 1; j <= n; j++) {
                cout << setw(2) << temp-- << " ";
            }
            num += n;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    printPattern(n);
    return 0;
}