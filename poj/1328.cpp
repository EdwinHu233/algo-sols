#include <algorithm>
#include <cmath>
#include <iostream>

struct Segment {
    double l, r;
    inline bool operator<(const Segment &rhs) const { return r < rhs.r; }
};

Segment ss[1000 + 5];
bool feasible;
int N, d;

bool init() {
    std::cin >> N >> d;
    if (N == 0) return false;
    feasible = true;
    int x, y;
    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y;
        if (y > d) feasible = false;
        double dx = std::sqrt(d * d - y * y);
        ss[i].l = x - dx;
        ss[i].r = x + dx;
    }
    return true;
}

int solve() {
    if (!feasible) return -1;
    std::sort(ss, ss + N);
    int cnt = 0, i = 0;
    while (i < N) {
        ++cnt;
        double radar = ss[i].r;
        while (i < N && ss[i].l <= radar) ++i;
    }
    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int t = 0;
    while (init()) {
        std::cout << "Case " << ++t << ": " << solve() << '\n';
    }
    return 0;
}
