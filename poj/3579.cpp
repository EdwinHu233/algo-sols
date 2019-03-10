#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 100000 + 10;

int xs[N];
int n, cn2, k;

bool init() {
    if (scanf("%d", &n) == EOF) return false;
    for (int i = 0; i < n; ++i) {
        scanf("%d", xs + i);
    }
    cn2 = n * (n - 1) / 2;
    k = (cn2 + 1) / 2;
    std::sort(xs, xs + n);
    return true;
}

bool C(int x) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (xs + n) - std::upper_bound(xs, xs + n, xs[i] + x);
        if (cnt > cn2 - k) return false;
    }
    return true;
}

int main() {
    while (init()) {
        int l = 0, h = xs[n - 1] - xs[0];
        while (l < h) {
            int mid = (h - l) / 2 + l;
            if (C(mid)) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", l);
    }
}
