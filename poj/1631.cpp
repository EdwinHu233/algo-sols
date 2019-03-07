#include <algorithm>
#include <cstdio>

const int P = 40000 + 10;
const int INF = 0x7fffffff;
int xs[P];
int dp[P];
int p;

inline int solve() {
    std::fill(dp, dp + p, INF);
    for (int i = 0; i < p; ++i) {
        // lower_bound or upper_bound, depending on problem
        *std::upper_bound(dp, dp + p, xs[i]) = xs[i];
    }
    // must be lower_bound
    return std::lower_bound(dp, dp + p, INF) - dp;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d", &xs[i]);
        }
        printf("%d\n", solve());
    }
    return 0;
}
