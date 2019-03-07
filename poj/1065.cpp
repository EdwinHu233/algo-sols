#include <algorithm>
#include <iostream>
#include <set>

typedef std::pair<int, int> Wood;
typedef std::set<int, std::greater<int>> ReverseSet;
const int N = 5000 + 10;
int n;
Wood ws[N];

void init() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> ws[i].first >> ws[i].second;
    }
}

int solve() {
    std::sort(ws, ws + n);
    ReverseSet s;
    s.insert(0);
    for (int i = 0; i < n; ++i) {
        int x = ws[i].second;
        ReverseSet::iterator it = s.lower_bound(x);
        if (it != s.end()) s.erase(it);
        s.insert(x);
    }
    return s.size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        init();
        std::cout << solve() << '\n';
    }
    return 0;
}
