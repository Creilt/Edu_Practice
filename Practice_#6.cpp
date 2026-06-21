#include <iostream>
int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        long long a = 0;
        long long b = 0;
        long long x = 0;
        long long y = 0;
        std::cin >> a >> b >> x >> y;
        long long pairs_B = std::min(b, x);
        long long pairs_A = std::min(a, (x - pairs_B) + y);
        std::cout << pairs_A + pairs_B << " ";
    }
    return 0;
}