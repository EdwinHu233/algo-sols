#include <iostream>

const int N = 1000000 + 5;
typedef unsigned long long u64;
const u64 M = 1000000000;
u64 dp[N];

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        if (i % 2) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = (dp[i - 1] + dp[i / 2]) % M;
        }
    }
    std::cout << (dp[n] % M) << '\n';
    return 0;
}
