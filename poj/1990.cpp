#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> P;

const int N = 20000 + 10;

struct BIT {
    LL xs[N];
    LL n;
    inline LL lowbit(LL i) { return i & (-i); }
    inline LL sum(LL i) {  // [1, i]
        LL ans = 0;
        while (i > 0) {
            ans += xs[i];
            i -= lowbit(i);
        }
        return ans;
    }
    inline LL sum(LL a, LL b) {  // [a, b]
        return sum(b) - sum(a - 1);
    }
    inline void add(LL i, LL x) {
        while (i <= n) {
            xs[i] += x;
            i += lowbit(i);
        }
    }
};

BIT dist, cnt;
P cow[N];  // (v, x)
LL n, max_x;

int main() {
    scanf("%lld", &n);
    max_x = 0;
    for (LL i = 0; i < n; ++i) {
        scanf("%lld%lld", &cow[i].first, &cow[i].second);
        max_x = max(max_x, cow[i].second);
    }
    sort(cow, cow + n);
    cnt.n = dist.n = max_x;
    LL ans = 0;
    for (LL i = 0; i < n; ++i) {
        LL v = cow[i].first, x = cow[i].second;
        LL lc = cnt.sum(1, x - 1), rc = cnt.sum(x + 1, max_x);
        LL ll = lc * x - dist.sum(1, x - 1),
           rl = dist.sum(x + 1, max_x) - rc * x;
        ans += v * (ll + rl);
        dist.add(x, x);
        cnt.add(x, 1);
    }
    printf("%lld\n", ans);
}
