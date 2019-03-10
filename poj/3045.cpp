#include <algorithm>
#include <cstdio>
using namespace std;

struct Cow {
    int w, s;
    bool operator<(const Cow &rhs) const { return w + s < rhs.w + rhs.s; }
};

Cow cs[50000 + 10];
int n;

void init() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        Cow &c = cs[i];
        scanf("%d%d", &c.w, &c.s);
    }
}

int solve() {
    sort(cs, cs + n);
    int sum_w = 0;
    int ans = 0x80000000;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, sum_w - cs[i].s);
        sum_w += cs[i].w;
    }
    return ans;
}

int main() {
    init();
    printf("%d\n", solve());
    return 0;
}
