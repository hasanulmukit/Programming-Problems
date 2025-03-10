#include <iostream>
#include <stack>
using namespace std;

void moveDisk(stack<int>& src, stack<int>& dest, char s, char d) {
    int pole1Top = src.empty() ? -1 : src.top();
    int pole2Top = dest.empty() ? -1 : dest.top();

    if (pole1Top == -1) {
        src.push(pole2Top);
        dest.pop();
        cout << "Move disk " << pole2Top << " from " << d << " to " << s << endl;
    } else if (pole2Top == -1) {
        dest.push(pole1Top);
        src.pop();
        cout << "Move disk " << pole1Top << " from " << s << " to " << d << endl;
    } else if (pole1Top > pole2Top) {
        src.push(pole1Top);
        src.push(pole2Top);
        dest.pop();
        cout << "Move disk " << pole2Top << " from " << d << " to " << s << endl;
    } else {
        dest.push(pole2Top);
        dest.push(pole1Top);
        src.pop();
        cout << "Move disk " << pole1Top << " from " << s << " to " << d << endl;
    }
}

void hanoi(int n, stack<int>& src, stack<int>& aux, stack<int>& dest) {
    int moves = (1 << n) - 1;
    char s = 'S', d = 'D', a = 'A';

    if (n % 2 == 0) swap(d, a);

    for (int i = n; i >= 1; i--) src.push(i);

    for (int i = 1; i <= moves; i++) {
        if (i % 3 == 1)
            moveDisk(src, dest, s, d);
        else if (i % 3 == 2)
            moveDisk(src, aux, s, a);
        else if (i % 3 == 0)
            moveDisk(aux, dest, a, d);
    }
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    stack<int> src, aux, dest;
    hanoi(n, src, aux, dest);

    return 0;
}
