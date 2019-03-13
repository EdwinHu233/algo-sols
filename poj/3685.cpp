#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;

LL n, m;

inline LL num_greater(const LL j, const LL x) {
    const LL a = (j - 100000) * j;
    const LL b = 100000 + j;
    if (n * (n + b) + a <= x) return 0;
    LL l = 1, h = n;
    while (l < h) {
        LL m = (h - l) / 2 + l;
        if (m * (m + b) + a > x) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return n - l + 1;
}

inline bool C(LL x) {
    const LL limit = n * n - m;
    LL cnt = 0;
    for (LL j = 1; j <= n; ++j) {
        cnt += num_greater(j, x);
        if (cnt > limit) return false;
    }
    return true;
}

int main() {
    LL t;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        LL l = -100000000000, r = 100000000000;
        while (l < r) {
            LL mid = (r - l) / 2 + l;
            if (C(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%lld\n", l);
    }
    return 0;
}
