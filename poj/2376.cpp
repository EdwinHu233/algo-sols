#include <algorithm>
#include <cstdio>

const int N = 25000 + 5;

struct Cow {
    int start, end;
    inline bool operator<(const Cow &rhs) const { return start < rhs.start; }
};

int n, t;
Cow cs[N];

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &cs[i].start, &cs[i].end);
    }
    std::sort(cs, cs + n);
    int start = 1, cnt = 0, i = 0;
    while (start >= 0 && start <= t) {
        int rightmost = -1;
        while (i < n && cs[i].start <= start) {
            rightmost = std::max(rightmost, cs[i].end);
            ++i;
        }
        if (rightmost < 0) {
            printf("-1\n");
            return 0;
        }
        start = rightmost + 1;
        ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
