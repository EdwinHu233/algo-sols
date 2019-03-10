#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;

typedef pair<double, int> P;

const double lb = 0.0, hb = 1e7;
const int N = 100000 + 10;
const double eps = 1e-8;

int v[N], w[N];
P work[N];
int n, k;

void init() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", v + i, w + i);
    }
}

inline bool C(double x) {
    for (int i = 0; i < n; ++i) {
        work[i].first = v[i] - x * w[i];
        work[i].second = i;
    }
    sort(work, work + n, greater<P>());
    double sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += work[i].first;
    }
    return sum >= 0;
}

int main() {
    init();
    double l = lb, h = hb;
    while (h - l > eps) {
        double mid = (l + h) / 2;
        if (C(mid)) {
            l = mid;
        } else {
            h = mid;
        }
    }
    for (int i = 0; i < k; ++i) {
        if (i != 0) printf(" ");
        printf("%d", work[i].second + 1);
    }
    printf("\n");
    return 0;
}
