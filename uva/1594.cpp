#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace std {
template <>
struct hash<std::vector<int>> {
    size_t operator()(const std::vector<int> &vec) const noexcept {
        size_t result = 0;
        for (auto i : vec) {
            result = (result * 73) + i;
        }
        return result;
    }
};
}  // namespace std

using Set = std::unordered_set<std::vector<int>>;

void evaluate(std::vector<int> &vec) {
    int last = vec.back();
    for (size_t i = 0; i < vec.size(); ++i) {
        int tmp = vec[i];
        vec[i] = std::abs(vec[i] - last);
        last = tmp;
    }
}

auto test = [](int i) { return i == 0; };

bool all_zero(std::vector<int> &vec) {
    Set set;
    set.insert(vec);
    for (size_t i = 0; i < 1000; ++i) {
        evaluate(vec);
        if (std::all_of(vec.begin(), vec.end(), test)) {
            return true;
        }
        if (set.count(vec)) {
            return false;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t num_tests;
    std::cin >> num_tests;
    while (num_tests--) {
        size_t len;
        std::cin >> len;
        std::vector<int> vec;
        while (len--) {
            vec.emplace_back();
            std::cin >> vec.back();
        }
        std::cout << (all_zero(vec) ? "ZERO" : "LOOP") << '\n';
    }
    return 0;
}
