#include <algorithm>
#include <cstdio>
#include <queue>

const int MAX_C = 100000 + 5;
typedef std::priority_queue<int> MaxQueue;
struct Cow {
    int s, f;
    bool operator<(const Cow &rhs) const { return s < rhs.s; }
};

Cow cs[MAX_C];
int N, C, F;
int half;
int left[MAX_C];   // minium money when select 'half' cows from cs[0,i]
int right[MAX_C];  // minium money when select 'half' cows from cs[i,C)

void init() {
    scanf("%d%d%d", &N, &C, &F);
    half = N / 2;
    for (int i = 0; i < C; ++i) {
        scanf("%d%d", &cs[i].s, &cs[i].f);
    }
    std::sort(cs, cs + C);
}

void prepare_left() {
    MaxQueue q;
    int sum = 0;
    for (int i = 0; i < half; ++i) {
        q.push(cs[i].f);
        sum += cs[i].f;
    }
    left[half - 1] = sum;
    for (int i = half; i < C; ++i) {
        if (cs[i].f < q.top()) {
            sum = sum - q.top() + cs[i].f;
            q.pop();
            q.push(cs[i].f);
        }
        left[i] = sum;
    }
}

void prepare_right() {
    MaxQueue q;
    int sum = 0;
    for (int i = C - half; i < C; ++i) {
        q.push(cs[i].f);
        sum += cs[i].f;
    }
    right[C - half] = sum;
    for (int i = C - half - 1; i >= 0; --i) {
        if (cs[i].f < q.top()) {
            sum = sum - q.top() + cs[i].f;
            q.pop();
            q.push(cs[i].f);
        }
        right[i] = sum;
    }
}

int solve() {
    for (int i = C - half - 1; i >= half; --i) {
        if (left[i - 1] + right[i + 1] + cs[i].f <= F) {
            return cs[i].s;
        }
    }
    return -1;
}

int main() {
    init();
    prepare_left();
    prepare_right();
    printf("%d\n", solve());
    return 0;
}
