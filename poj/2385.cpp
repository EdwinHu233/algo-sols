#include <cstring>
#include <iostream>

const int W = 35;
int x[W];

inline int jump_to_tree(int jump) { return (jump % 2 == 0) ? 1 : 2; }

int main() {
    std::ios_base::sync_with_stdio(false);
    int t, w;
    std::cin >> t >> w;
    for (int i = 0; i < t; ++i) {
        int tree;
        std::cin >> tree;
        for (int j = w; j > 0; --j) {
            x[j] = std::max(x[j] + (jump_to_tree(j) == tree),
                            x[j - 1] + (jump_to_tree(j - 1) == tree));
        }
        x[0] = x[0] + (jump_to_tree(0) == tree);
    }
    int max_x = -1;
    for (int i = 0; i <= w; ++i) {
        max_x = std::max(max_x, x[i]);
    }
    std::cout << max_x << '\n';
    return 0;
}
