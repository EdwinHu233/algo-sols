#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100000 + 10;
int n, m;
int xs[N], lb, hb;

void init() {
    lb = -1;
    hb = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", xs + i);
        lb = max(lb, xs[i]);
        hb += xs[i];
    }
}

inline bool feasible(int x) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (sum + xs[i] > x) {
            ++cnt;
            sum = xs[i];
        } else {
            sum += xs[i];
        }
    }
    if (sum + xs[n - 1] <= x) {
        cnt += 1;
    } else {
        cnt += 2;
    }
    return cnt <= m;
}

void solve() {
    int l = lb, h = hb;
    while (l < h) {
        int mid = (h - l) / 2 + l;
        if (feasible(mid)) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", l);
}

int main() {
    init();
    solve();
    return 0;
}
