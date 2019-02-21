#include <iostream>
#include <stack>

const int MAX = 1005;
int target[MAX];

bool check(int n) {
    std::stack<int> stk;
    int s = 1, t = 1;
    while (s <= n && t <= n) {
        if (!stk.empty() && stk.top() == target[t]) {
            stk.pop();
            ++t;
        } else {
            stk.push(s++);
        }
    }
    while (!stk.empty()) {
        if (stk.top() != target[t]) return false;
        stk.pop();
        ++t;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    while (std::cin >> n && n) {
        while (std::cin >> target[1] && target[1]) {
            for (int i = 2; i <= n; ++i) std::cin >> target[i];
            std::cout << (check(n) ? "Yes" : "No") << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}
