#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::reverse(str.begin(), str.end());

    std::cout << "Reversed string: " << str << std::endl;

    return 0;
}
