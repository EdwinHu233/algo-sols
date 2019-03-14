#include <cstdio>
#include <map>
#include <set>
using namespace std;

const int P = 1000000 + 10;

int xs[P];
set<int> s;
map<int, int> m;
int p;

void init() {
    scanf("%d", &p);
    for (int i = 0; i < p; ++i) {
        scanf("%d", xs + i);
        s.insert(xs[i]);
    }
}

int solve() {
    int a = 0, b = 0;  // [a, b)
    int ans = 0x7f7f7f7f;
    unsigned cnt = 0;
    while (a < p && b <= p) {
        if (cnt < s.size() && b < p) {
            if (++m[xs[b]] == 1) ++cnt;
            ++b;
        } else {
            if (cnt == s.size()) ans = min(ans, b - a);
            if (--m[xs[a]] == 0) --cnt;
            ++a;
        }
    }
    return ans;
}

int main() {
    init();
    printf("%d\n", solve());
}
