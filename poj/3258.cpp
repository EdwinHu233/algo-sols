#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 50000 + 10;
int xs[N];
int n, m;

void init() {
    int l;
    scanf("%d%d%d", &l, &n, &m);
    n += 2;
    xs[0] = 0;
    xs[n - 1] = l;
    for (int i = 1; i < n - 1; ++i) {
        scanf("%d", xs + i);
    }
    sort(xs, xs + n);
}

inline bool feasible(int x) {
    int prev = 0, cnt = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (xs[i] - xs[prev] < x) {
            ++cnt;
        } else {
            prev = i;
        }
    }
    if (xs[n - 1] - xs[prev] < x) {
        if (prev == 0)
            return false;
        else
            ++cnt;
    }
    return cnt <= m;
}

void solve() {
    int l = 0, h = 1000000000 + 1;
    while (h - l > 1) {
        int mid = (h - l) / 2 + l;
        if (feasible(mid)) {
            l = mid;
        } else {
            h = mid;
        }
    }
    printf("%d\n", l);
}

int main() {
    init();
    solve();
    return 0;
}
