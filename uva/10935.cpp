#include <iostream>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    bool is_first = true;
    while (std::cin >> n && n) {
        if (!is_first) std::cout << '\n';
        is_first = false;
        std::queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(i);
        std::cout << "Discarded cards: ";
        while (q.size() > 1) {
            auto x = q.front();
            q.pop();
            std::cout << x;
            q.push(q.front());
            q.pop();
            if (q.size() > 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\nRemaining card: " << q.front();
    }
    return 0;
}
