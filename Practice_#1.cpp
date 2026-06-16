#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main() {
    std::string s = "";
	int n = 0;
	int sum = 0;
	std::cin >> n;
	int matrix[n][n];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        matrix[i][j] = -1;
	    }
	}
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < i + 1; j++) {
	        std::cin >> matrix[i][j];
	    }
    }
    int child = matrix[0][0];
    sum = child;
    s = std::to_string(child) + " ";
    for (int i = 0; i < n; i++) {
	    for (int j = 0; j <= i; j++) {
	        if (child == matrix[i][j]) {
	            int l = matrix[i + 1][j];
	            int r = matrix[i + 1][j + 1];
	            child = std::min(l, r);
	            if (l > r) {
	                sum = sum + r;
	                s = s + std::to_string(r) + " ";
	            } else {
	                sum = sum + l;
	                s = s + std::to_string(l) + " ";
	            }
	        } else {
	            break;
	        }
        }
    }
    std::cout << sum << "\n" << s;
}