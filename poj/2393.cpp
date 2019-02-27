#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    int N, S;
    std::cin >> N >> S;
    long long sum = 0;
    int min_c = 100000000, c, y;
    for (int i = 0; i < N; ++i) {
        std::cin >> c >> y;
        min_c = std::min(min_c + S, c);
        sum += min_c * y;
    }
    std::cout << sum << '\n';
    return 0;
}
