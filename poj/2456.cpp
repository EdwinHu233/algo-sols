#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100000 + 10;
int xs[N];
int n, c;

void init() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d", xs + i);
    }
}

inline bool feasible(int d) {
    int last = 0;
    for (int i = 1; i < c; ++i) {
        int j = last + 1;
        while (j < n && xs[j] - xs[last] < d) {
            ++j;
        }
        if (j >= n) return false;
        last = j;
    }
    return true;
}

void solve() {
    sort(xs, xs + n);
    int l = 0, h = xs[n - 1] + 1;
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
