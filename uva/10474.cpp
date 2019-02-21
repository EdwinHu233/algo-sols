#include <algorithm>
#include <iostream>

const int MAX = 10000;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int n, q, x, nums[MAX];
    int case_count = 0;
    while ((std::cin >> n >> q) && n && q) {
        std::cout << "CASE# " << (++case_count) << ":\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> nums[i];
        }
        std::sort(nums, nums + n);
        while (q--) {
            std::cin >> x;
            auto p = std::lower_bound(nums, nums + n, x);
            if (p == nums + n || *p != x) {
                std::cout << x << " not found\n";
            } else {
                std::cout << x << " found at " << p - nums + 1 << "\n";
            }
        }
    }
    return 0;
}
