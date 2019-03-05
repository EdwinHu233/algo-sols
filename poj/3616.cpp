#include <algorithm>
#include <iostream>

struct Time {
    int a, b, out;
    inline bool operator<(const Time &rhs) const { return b < rhs.b; }
};

const int M = 1005;
Time ts[M];
int dp[M];

inline int best_prev(int i) {
    int ans = 0;
    for (int j = 0; j < i && ts[j].b <= ts[i].a; ++j) {
        ans = std::max(ans, dp[j]);
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, r;
    std::cin >> n >> m >> r;
    for (int i = 0; i < m; ++i) {
        std::cin >> ts[i].a >> ts[i].b >> ts[i].out;
        ts[i].b += r;
    }
    std::sort(ts, ts + m);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        dp[i] = best_prev(i) + ts[i].out;
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';
    return 0;
}
