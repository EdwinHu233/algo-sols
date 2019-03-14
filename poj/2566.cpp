#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair<int, int> P;  // (sum, i)
const int N = 100000 + 10;

P xs[N];
int n, k, t;

bool init() {
    scanf("%d %d", &n, &k);
    if (n == 0) return false;
    xs[0] = P(0, 0);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        xs[i].first = xs[i - 1].first + tmp;
        xs[i].second = i;
    }
    sort(xs, xs + n + 1);
    return true;
}

void solve() {
    int a = 0, b = 1;
    int aa, bb, dd = 0x7f7f7f7f;
    while (a <= n && b <= n) {
        int s = xs[b].first - xs[a].first;
        if (abs(s - t) < dd) {
            aa = a;
            bb = b;
            dd = abs(s - t);
        }
        if (s < t) {
            ++b;
        } else if (s > t) {
            ++a;
        } else {
            break;
        }
        if (a == b) ++b;
    }
    int ans = xs[bb].first - xs[aa].first;
    int l = min(xs[aa].second, xs[bb].second);
    int r = max(xs[aa].second, xs[bb].second);
    printf("%d %d %d\n", ans, l + 1, r);
}

int main() {
    while (init()) {
        while (k--) {
            scanf("%d", &t);
            solve();
        }
    }
}
