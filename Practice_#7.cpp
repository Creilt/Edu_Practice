#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::string s = " ";
    std::cin >> s;
    if (s.size() == 6) {
        if (isalpha(s[0]) and isdigit(s[1]) and isdigit(s[2]) and isdigit(s[3]) and isalpha(s[4]) and isalpha(s[5])) {
            std::cout << "Yes" << std::endl;
            return 0;
        } else {
            std::cout << "No" << std::endl;
            return 0;
        }
    } else {
        std::cout << "No" << std::endl;
        return 0;
    }
}