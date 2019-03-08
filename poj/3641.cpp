#include <cstdio>

typedef unsigned long long ULL;

inline ULL mod_pow(ULL x, ULL n, ULL mod) {
    ULL ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}

inline bool is_prime(ULL p) {
    for (ULL i = 2; i * i <= p; ++i) {
        if (p % i == 0) return false;
    }
    return true;
}

int main() {
    ULL p, a;
    while (true) {
        scanf("%llu%llu", &p, &a);
        if (p == 0) return 0;
        if (!is_prime(p) && mod_pow(a, p, p) == a) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
