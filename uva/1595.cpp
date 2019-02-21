#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using Vector = std::vector<int>;
using Dict = std::unordered_map<int, Vector>;

bool is_symmetric(Dict &dots_by_y) {
    for (auto &item : dots_by_y) {
        auto &xs = item.second;
        std::sort(xs.begin(), xs.end());
    }
    auto &xs = dots_by_y.begin()->second;
    const int SUM = xs.front() + xs.back();
    for (auto &item : dots_by_y) {
        auto &xs = item.second;
        for (size_t i = 0; i < xs.size(); ++i) {
            size_t j = xs.size() - 1 - i;
            if (i > j) break;
            if (xs[i] + xs[j] != SUM) return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t num_test;
    std::cin >> num_test;
    while (num_test--) {
        Dict dots_by_y;
        size_t num_dot;
        std::cin >> num_dot;
        while (num_dot--) {
            int x, y;
            std::cin >> x >> y;
            if (!dots_by_y.count(y)) {
                dots_by_y[y] = Vector();
            }
            dots_by_y[y].push_back(x);
        }
        std::cout << (is_symmetric(dots_by_y) ? "YES" : "NO") << '\n';
    }
    return 0;
}
