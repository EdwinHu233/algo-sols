#include <algorithm>
#include <iostream>

const int MAX = 10000;
int sum_by_pos[MAX];

void build(int pos) {
    int val;
    std::cin >> val;
    if (val < 0) return;
    sum_by_pos[pos] += val;
    build(pos - 1);
    build(pos + 1);
}

bool init() {
    int val;
    std::cin >> val;
    if (val < 0) return false;
    std::fill_n(sum_by_pos, MAX, 0);
    int pos = MAX / 2;
    sum_by_pos[pos] = val;
    build(pos - 1);
    build(pos + 1);
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num_test = 0;
    while (init()) {
        std::cout << "Case " << ++num_test << ":\n";
        int i = 0;
        while (sum_by_pos[i] == 0) ++i;
        std::cout << sum_by_pos[i++];
        while (sum_by_pos[i] != 0) {
            std::cout << ' ' << sum_by_pos[i++];
        }
        std::cout << "\n\n";
    }
    return 0;
}
