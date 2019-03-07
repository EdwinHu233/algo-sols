#include <algorithm>
#include <cstdio>

const int N = 2000 + 10;
int a[N], b[N];
int dp[2][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    std::sort(b, b + n);
    int *last = dp[0], *cur = dp[1];
    for (int i = 0; i < n; ++i) {
        int m = 0x7fffffff;
        for (int j = 0; j < n; ++j) {
            m = std::min(m, last[j]);
            cur[j] = m + std::abs(a[i] - b[j]);
        }
        std::swap(last, cur);
    }
    printf("%d\n", *std::min_element(last, last + n));
    return 0;
}
