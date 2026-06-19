
#include <iostream>
#include <string>
#include <vector>
int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::string s = " ";
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        p[i]--;
    }
    std::vector<int> inv(n);
    for (int i = 0; i < n; i++) {
        inv[p[i]] = i;
    }
    std::cin >> s;
    for (int i = 0; i < k; ++i) {
        std::string word(n, ' ');
        for (int j = 0; j < n; ++j) {
            word[j] = s[inv[j]];
        }
        s = word;
    }
    std::cout << s << std::endl;
    return 0;
}
