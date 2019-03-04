#include <algorithm>
#include <cstring>
#include <iostream>

const int N = 22;

struct Coin {
    int val, num;
    bool operator<(const Coin &rhs) const { return val < rhs.val; }
};

Coin cs[N];
int plan[N];
int n, c;

bool get_plan() {
    int remain = c;
    for (int i = n - 1; i >= 0; --i) {
        plan[i] = std::min(cs[i].num, remain / cs[i].val);
        remain -= plan[i] * cs[i].val;
    }
    if (remain == 0) return true;
    for (int i = 0; i < n; ++i) {
        if (cs[i].num > plan[i]) {
            ++plan[i];
            return true;
        }
    }
    return false;
}

int use_plan() {
    int cnt = 0x7fffffff;
    for (int i = 0; i < n; ++i) {
        if (plan[i] == 0) continue;
        cnt = std::min(cnt, cs[i].num / plan[i]);
    }
    for (int i = 0; i < n; ++i) {
        cs[i].num -= cnt * plan[i];
    }
    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        std::cin >> cs[i].val >> cs[i].num;
    }
    std::sort(cs, cs + n);
    int ans = 0;
    while (get_plan()) {
        ans += use_plan();
    }
    std::cout << ans << '\n';
    return 0;
}
