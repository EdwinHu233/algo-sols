#include <iostream>

const int N = 3500, W = 13000;
int ws[N], vs[N];
int dp[W];

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> ws[i] >> vs[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= ws[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - ws[i]] + vs[i]);
        }
    }
    std::cout << dp[m] << '\n';
    return 0;
}
