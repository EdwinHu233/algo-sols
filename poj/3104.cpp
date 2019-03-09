#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100000 + 10;
int xs[N];
int n, k;
int max_t;

void init() {
    max_t = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", xs + i);
        max_t = max(max_t, xs[i]);
    }
    scanf("%d", &k);
}

inline bool C(int x) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (xs[i] <= x) continue;
        sum += (xs[i] - x + k - 2) / (k - 1);
    }
    return sum <= x;
}

void solve() {
    if (k == 1) {
        printf("%d\n", max_t);
    } else {
        int l = 0, h = max_t;
        while (l < h) {
            int mid = (h - l) / 2 + l;
            if (C(mid))
                h = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l);
    }
}

int main() {
    init();
    solve();
    return 0;
}
