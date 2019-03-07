#include <algorithm>
#include <cstdio>
#include <queue>

const int N = 2500 + 5;
typedef std::pair<int, int> Cow;     // (min_spf, max_spf)
typedef std::pair<int, int> Bottle;  // (spf, cnt)
typedef std::priority_queue<int, std::vector<int>, std::greater<int>> MinQ;

Cow cs[N];
Bottle bs[N];
int cn, bn;
MinQ min_q;

void init() {
    scanf("%d%d", &cn, &bn);
    for (int i = 0; i < cn; ++i) {
        scanf("%d%d", &cs[i].first, &cs[i].second);
    }
    for (int i = 0; i < bn; ++i) {
        scanf("%d%d", &bs[i].first, &bs[i].second);
    }
}

int solve() {
    std::sort(cs, cs + cn);
    std::sort(bs, bs + bn);
    int j = 0;  // index for scanning cs
    int ans = 0;
    for (int i = 0; i < bn; ++i) {
        Bottle &cur = bs[i];
        while (j < cn && cs[j].first <= cur.first) {
            min_q.push(cs[j].second);
            ++j;
        }
        while (!min_q.empty() && cur.second > 0) {
            if (min_q.top() >= cur.first) {
                ++ans;
                --cur.second;
            }
            min_q.pop();
        }
    }
    return ans;
}

int main() {
    init();
    printf("%d\n", solve());
    return 0;
}
