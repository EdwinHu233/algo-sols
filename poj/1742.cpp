#include <cstring>
#include <iostream>

const int N = 105, M = 100010;

struct Coin {
    int a, c;
};

Coin cs[N];
int dp[M];
int n, m;

bool init() {
    std::cin >> n >> m;
    if (n == 0) return false;
    for (int i = 0; i < n; ++i) {
        std::cin >> cs[i].a;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> cs[i].c;
    }
    return true;
}

int solve() {
    std::memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dp[j] >= 0) {
                dp[j] = cs[i].c;
            } else if (j < cs[i].a || dp[j - cs[i].a] < 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - cs[i].a] - 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (dp[i] >= 0) ++ans;
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (init()) std::cout << solve() << '\n';
    return 0;
}
