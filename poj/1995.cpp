#include <cstdio>

typedef unsigned long long ULL;

inline ULL mod_pow(ULL x, ULL n, ULL mod) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    ULL ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ULL sum = 0;
        int m, h;
        scanf("%d%d", &m, &h);
        while (h--) {
            ULL a, b;
            scanf("%llu%llu", &a, &b);
            sum = (sum + mod_pow(a, b, m)) % m;
        }
        printf("%llu\n", sum);
    }
    return 0;
}
