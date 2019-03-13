#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;
const int N = 1000000;
const int BS = 100;

ULL n;
ULL xs[N], ys[N], zs[N];
char buffer[BS];

bool init() {
    while (true) {
        if (!fgets(buffer, BS, stdin)) return false;
        if (buffer[0] != '\n') break;
    }
    n = 0;
    while (true) {
        sscanf(buffer, "%llu%llu%llu", xs + n, ys + n, zs + n);
        ++n;
        if (!fgets(buffer, BS, stdin) || buffer[0] == '\n') break;
    }
    return true;
}

inline ULL C(ULL x) {
    ULL ans = 0;
    for (ULL i = 0; i < n; ++i) {
        ULL top = min(ys[i], x);
        if (xs[i] <= top) ans += (top - xs[i]) / zs[i] + 1;
    }
    return ans;
}

int main() {
    while (init()) {
        ULL low = 0, high = 0x7fffffff;
        while (low < high) {
            ULL mid = (high - low) / 2 + low;
            if (C(mid) % 2 == 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (low == 0x7fffffff) {
            printf("no corruption\n");
        } else {
            printf("%llu %llu\n", low, C(low) - C(low - 1));
        }
    }
}
