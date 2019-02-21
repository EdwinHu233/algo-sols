#include <iostream>
#include <unordered_map>

using Pair = std::pair<size_t, size_t>;

template <>
struct std::hash<Pair> {
    size_t operator()(const Pair &p) const noexcept {
        return p.first * 1234567 + p.second;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t n;
    while (std::cin >> n && n) {
        std::unordered_map<Pair, size_t> cnt;
        size_t a, b;
        while (n--) {
            std::cin >> a >> b;
            if (cnt.count(Pair(b, a))) {
                if (--cnt[Pair(b, a)] == 0) {
                    cnt.erase(Pair(b, a));
                }
            } else if (cnt.count(Pair(a, b))) {
                ++cnt[Pair(a, b)];
            } else {
                cnt[Pair(a, b)] = 1;
            }
        }
        std::cout << (cnt.empty() ? "YES" : "NO") << '\n';
    }
    return 0;
}
