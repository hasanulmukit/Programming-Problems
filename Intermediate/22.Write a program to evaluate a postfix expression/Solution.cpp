#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> s;
    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression;
    cout << "Enter postfix expression: ";
    cin >> expression;

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
