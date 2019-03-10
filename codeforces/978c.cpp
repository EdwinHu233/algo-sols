#include <algorithm>
#include <cstdio>

typedef unsigned long long ULL;
const int N = 200000 + 10;
ULL sum_before[N];
int n, m;

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%llu", sum_before + i + 1);
        sum_before[i + 1] += sum_before[i];
    }
}

void solve(ULL x) {
    ULL *it = std::lower_bound(sum_before, sum_before + n + 2, x);
    --it;
    printf("%llu %llu\n", ULL(it - sum_before), x - *it);
}

int main() {
    init();
    while (m--) {
        ULL x;
        scanf("%llu", &x);
        solve(x);
    }
}

