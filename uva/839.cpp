#include <iostream>

int is_balance() {
    int w1, d1, w2, d2;
    std::cin >> w1 >> d1 >> w2 >> d2;
    if (w1 == 0) w1 = is_balance();
    if (w2 == 0) w2 = is_balance();
    if (w1 < 0 || w2 < 0 || w1 * d1 != w2 * d2) {
        return -1;
    } else {
        return w1 + w2;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num_test;
    std::cin >> num_test;
    bool is_first = true;
    while (num_test--) {
        if (!is_first) std::cout << '\n';
        is_first = false;
        std::cout << (is_balance() >= 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
