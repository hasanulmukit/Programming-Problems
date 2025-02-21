#include <iostream>
#include <string>
using namespace std;

string compressString(const string& str) {
    string compressed = "";
    int count = 1;

    for (size_t i = 0; i < str.length(); i++) {
        if (i < str.length() - 1 && str[i] == str[i + 1]) {
            count++;
        } else {
            compressed += str[i] + to_string(count);
            count = 1;
        }
    }

    return compressed;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string result = compressString(str);
    cout << "Compressed string: " << result << endl;

    return 0;
}
