#include <iostream>

const int T = 1000 + 5, N = 100 + 5;
const int ALL = T * N;
const int MOD = 1000000;

int num[T];
int dp[2][ALL];
int t, a, s, b;

void init() {
    std::cin >> t >> a >> s >> b;
    for (int i = 0; i < a; ++i) {
        int x;
        std::cin >> x;
        num[x - 1]++;  // type starts at 0
    }
}

int solve() {
    int *last = dp[0], *cur = dp[1];
    last[0] = 1;
    for (int i = 0; i < t; ++i) {
        cur[0] = last[0];
        for (int j = 1; j <= num[i]; ++j) {
            cur[j] = (cur[j - 1] + last[j]) % MOD;
        }
        for (int j = num[i] + 1; j <= b; ++j) {
            cur[j] = (cur[j - 1] + last[j] - last[j - num[i] - 1] + MOD) % MOD;
        }
        std::swap(last, cur);
    }
    int ans = 0;
    for (int j = s; j <= b; ++j) {
        ans = (ans + last[j]) % MOD;
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    init();
    std::cout << solve() << '\n';
    return 0;
}
