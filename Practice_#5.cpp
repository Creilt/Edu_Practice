#include <iostream>
#include <vector>

int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<std::vector<int>> arr(n, std::vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> arr[i][j];
        }
    }
    int minx = n;
    int miny = k;
    int maxx = 0;
    int maxy = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (arr[i][j] == 1) {
               if (i < minx) {
                   minx = i;
               }
               if (j < miny) {
                   miny = j;
               }
               if (i > maxx) {
                   maxx = i;
               }
               if (j > maxy) {
                   maxy = j;
               }
            }
        }
    }
    minx--;
    miny--;
    maxx++;
    maxy++;
    std::cout << minx << " " << miny << " " << maxx << " " << maxy;
}