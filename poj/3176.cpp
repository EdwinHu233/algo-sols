#include <iostream>

const int N = 350 + 5;
int ns[N][N];

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cin >> ns[i][j];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            ns[i][j] += std::max(ns[i + 1][j], ns[i + 1][j + 1]);
        }
    }
    std::cout << ns[0][0] << '\n';
    return 0;
}
