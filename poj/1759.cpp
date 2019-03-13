#include <cstdio>

int n;
double a, b;

bool C(double x) {
    double x1 = a, x2 = x, x3;
    for (int i = 3; i <= n; ++i) {
        x3 = 2 * (x2 + 1) - x1;
        if (x3 < 0) return false;
        x1 = x2;
        x2 = x3;
    }
    if (x2 < b) b = x2;
    return true;
}

int main() {
    scanf("%d%lf", &n, &a);
    b = 1e8;
    double low = 0, high = a;
    for (int i = 0; i < 100; ++i) {
        double mid = (low + high) / 2;
        if (C(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.2lf\n", b);
}
