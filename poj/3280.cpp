#include <cstring>
#include <iostream>

const int M = 2000 + 5;

std::string s;
int dp[M][M];
int min_cost[26];

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::cin >> s;
    while (n--) {
        char c;
        int add, del;
        std::cin >> c >> add >> del;
        min_cost[c - 'a'] = std::min(add, del);
    }
    for (int i = m - 1; i >= 0; --i) {
        for (int j = i + 1; j <= m - 1; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                int x = s[i] - 'a', y = s[j] - 'a';
                dp[i][j] = std::min(dp[i + 1][j] + min_cost[x],
                                    dp[i][j - 1] + min_cost[y]);
            }
        }
    }
    std::cout << dp[0][m - 1] << '\n';
    return 0;
}
