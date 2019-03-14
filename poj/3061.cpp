#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100000 + 5;
int xs[N];
int n, s;

void init() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", xs + i);
    }
}

int solve() {
    int begin = 0, end = 0, sum = 0;
    int ans = 0x7f7f7f7f;
    while (begin < n) {
        while (end < n && sum < s) {
            sum += xs[end];
            ++end;
        }
        if (sum < s) break;
        ans = min(ans, end - begin);
        sum -= xs[begin];
        ++begin;
    }
    return (ans == 0x7f7f7f7f) ? 0 : ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        printf("%d\n", solve());
    }
}
