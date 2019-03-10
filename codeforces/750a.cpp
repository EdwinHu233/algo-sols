#include <cstdio>

int n, k;

bool c(int x) { return x * (x + 1) * 5 <= 2 * (240 - k); }

int main() {
    scanf("%d%d", &n, &k);
    int l = 0, h = n;
    while (l < h) {
        int mid = (h - l + 1) / 2 + l;
        if (c(mid))
            l = mid;
        else
            h = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}
