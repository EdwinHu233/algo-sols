#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;
const ULL N = 100000 + 10;
ULL xs[N];
ULL n, k;
ULL max_t;

void init() {
    max_t = 0;
    scanf("%llu", &n);
    for (ULL i = 0; i < n; ++i) {
        scanf("%llu", xs + i);
        max_t = max(max_t, xs[i]);
    }
    scanf("%llu", &k);
}

inline bool C(ULL x) {
    ULL sum = 0;
    for (ULL i = 0; i < n; ++i) {
        if (xs[i] <= x) continue;
        sum += (xs[i] - x + k - 2) / (k - 1);
    }
    return sum <= x;
}

void solve() {
    if (k == 1) {
        printf("%llu\n", max_t);
    } else {
        ULL l = 0, h = max_t;
        while (l < h) {
            ULL mid = (h - l) / 2 + l;
            if (C(mid))
                h = mid;
            else
                l = mid + 1;
        }
        printf("%llu\n", l);
    }
}

int main() {
    init();
    solve();
    return 0;
}
