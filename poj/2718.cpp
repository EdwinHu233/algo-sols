#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

int nums[10];

int array_to_int(int b, int e) {
    if (nums[b] == 0) {
        return (e - b == 1) ? 0 : -1;
    }
    int x = 0;
    for (int i = b; i < e; ++i) {
        x = nums[i] + x * 10;
    }
    return x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int t;
    std::cin >> t;
    std::string line;
    std::getline(std::cin, line);  // '\n'
    while (t--) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int x, n = 0;
        int min_diff = 0x7fffffff;
        while (iss >> x) nums[n++] = x;
        do {
            int x = array_to_int(0, n / 2);
            if (x < 0) continue;
            int y = array_to_int(n / 2, n);
            if (y < 0) continue;
            min_diff = std::min(min_diff, std::abs(x - y));
        } while (std::next_permutation(nums, nums + n));
        std::cout << min_diff << '\n';
    }
    return 0;
}
