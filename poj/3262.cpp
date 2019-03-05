#include <algorithm>
#include <iostream>

typedef long long LL;

struct Cow {
    int t, d;
    bool operator<(const Cow &rhs) const { return d * rhs.t > t * rhs.d; }
};

Cow cs[100000 + 10];

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    LL sum_d = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> cs[i].t >> cs[i].d;
        sum_d += cs[i].d;
    }
    std::sort(cs, cs + n);
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        sum_d -= cs[i].d;
        ans += sum_d * cs[i].t;
    }
    std::cout << ans * 2 << '\n';
    return 0;
}
