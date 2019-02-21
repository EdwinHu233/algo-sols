#include <bitset>
#include <iostream>

int D, I;
inline int left(int x) { return x << 1; }
inline int right(int x) { return (x << 1) + 1; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tests;
    std::cin >> tests;
    while (tests--) {
        std::cin >> D >> I;
        --I;
        int x = 1;
        for (int d = 1; d < D; ++d) {
            x = (I & 1) ? right(x) : left(x);
            I >>= 1;
        }
        std::cout << x << '\n';
    }
    return 0;
}
