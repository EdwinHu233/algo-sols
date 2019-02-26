#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1005;
int pos[N];
int r, n;

int rightmost_in_r(int i) {
    int j = i;
    while (j < n && pos[j] - pos[i] <= r) ++j;
    return j - 1;
}

int solve() {
    int cnt = 0, cur = 0;
    while (cur < n) {
        ++cnt;
        int center = rightmost_in_r(cur);
        cur = rightmost_in_r(center) + 1;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> r >> n && r >= 0) {
        for (int i = 0; i < n; ++i) cin >> pos[i];
        sort(pos, pos + n);
        cout << solve() << '\n';
    }
    return 0;
}
