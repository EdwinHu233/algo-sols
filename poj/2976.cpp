#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;
const int N = 1000 + 10;

ULL a[N], b[N];
double work[N];
int n, k;

bool C(double x) {
    x /= 100;
    for (int i = 0; i < n; ++i) {
        work[i] = a[i] - x * b[i];
    }
    sort(work, work + n);
    double sum = 0.0;
    for (int i = k; i < n; ++i) {
        sum += work[i];
    }
    return sum >= 0;
}

bool init() {
    scanf("%d%d", &n, &k);
    if (n == 0) return false;
    for (int i = 0; i < n; ++i) {
        scanf("%llu", a + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%llu", b + i);
    }
    return true;
}

int main() {
    while (init()) {
        double l = 0.0, h = 100.0;
        for (int i = 0; i < 100; ++i) {
            double mid = (l + h) / 2;
            if (C(mid)) {
                l = mid;
            } else {
                h = mid;
            }
        }
        printf("%d\n", int(l + 0.5));
    }
    return 0;
}
