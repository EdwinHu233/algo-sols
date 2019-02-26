#include <cstring>
#include <iostream>

const int M = 100000 + 10, N = 100 + 5;
int m, n;
int dp[M];
int as[N], cs[N];

bool init() {
    std::cin >> n >> m;
    if (n == 0) return false;
    for (int i = 0; i < n; ++i) {
        std::cin >> as[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> cs[i];
    }
    std::memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    return true;
}

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dp[j] >= 0) {
                dp[j] = cs[i];
            } else if (j < as[i] || dp[j - as[i]] < 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - as[i]] - 1;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (init()) {
        solve();
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            if (dp[i] >= 0) ++cnt;
        }
        std::cout << cnt << '\n';
    }
    return 0;
}
