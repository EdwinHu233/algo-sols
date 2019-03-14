#include <cstdio>
#include <vector>
using namespace std;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> P;

inline ULL get_ub(ULL x) {
    ULL l = 0, h = x;
    while (l < h) {
        ULL mid = (h - l + 1) / 2 + l;
        if (mid * (mid + 1) * (2 * mid + 1) <= 6 * x) {
            l = mid;
        } else {
            h = mid - 1;
        }
    }
    // printf("***%llu***\n", l);
    return l;
}

inline void solve(const ULL x) {
    vector<P> ans;
    ULL a = 1, b = get_ub(x);
    ULL sum = b * (b + 1) * (2 * b + 1) / 6;
    while (b * b <= x) {
        if (sum < x) {
            ++b;
            sum += b * b;
        } else {
            if (sum == x) {
                ans.push_back(P(a, b));
            }
            sum -= a * a;
            ++a;
        }
    }
    printf("%llu\n", ULL(ans.size()));
    for (ULL i = 0; i < ans.size(); ++i) {
        ULL a = ans[i].first, b = ans[i].second;
        printf("%llu", b - a + 1);
        for (ULL i = a; i <= b; ++i) {
            printf(" %llu", i);
        }
        printf("\n");
    }
}

int main() {
    ULL x;
    scanf("%llu", &x);
    solve(x);
}
