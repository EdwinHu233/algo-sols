#include <cstring>
#include <iostream>

const int W = 10000 + 5, N = 500 + 5;
int w, n;
int dp[W];
int vs[N], ws[N];

void solve() {
    std::memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = ws[i]; j <= w; ++j) {
            int x = dp[j], y = dp[j - ws[i]];
            if (x < 0) {
                dp[j] = (y < 0) ? -1 : (y + vs[i]);
            } else {
                dp[j] = (y < 0) ? x : std::min(x, y + vs[i]);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        int e, f;
        std::cin >> e >> f;
        w = f - e;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> vs[i] >> ws[i];
        }
        solve();
        if (dp[w] < 0) {
            std::cout << "This is impossible.\n";
        } else {
            std::cout << "The minimum amount of money in the piggy-bank is "
                      << dp[w] << ".\n";
        }
    }
    return 0;
}
