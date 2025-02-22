#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

void reverseWords(string str) {
    stack<string> words;
    stringstream ss(str);
    string word;

    while (ss >> word) {
        words.push(word);
    }

    cout << "Reversed sentence: ";
    while (!words.empty()) {
        cout << words.top() << " ";
        words.pop();
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);

    reverseWords(str);
    return 0;
}
