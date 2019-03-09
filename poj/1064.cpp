#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 10000 + 10;
const double INF = 1e5;

double xs[N];
int n, k;

inline bool feasible(double a) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += int(xs[i] / a);
    }
    return sum >= k;
}

void solve() {
    double l = 0.0, h = INF;
    for (int i = 0; i < 100; ++i) {
        double mid = (h - l) / 2 + l;
        if (feasible(mid)) {
            l = mid;
        } else {
            h = mid;
        }
    }
    printf("%.2lf\n", floor(l * 100) / 100);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", xs + i);
    }
    solve();
    return 0;
}
