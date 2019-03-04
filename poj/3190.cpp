#include <algorithm>
#include <iostream>
#include <queue>

struct Stall {
    int id, end_time;
    bool operator<(const Stall &rhs) const { return end_time > rhs.end_time; }
};

struct Cow {
    int begin, end, id;
    bool operator<(const Cow &rhs) const { return begin < rhs.begin; }
};

std::priority_queue<Stall> pq;
const int N_MAX = 50000 + 10;
Cow cs[N_MAX];
int cow_to_stall[N_MAX];
int N;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> cs[i].begin >> cs[i].end;
        cs[i].id = i;
    }
    std::sort(cs, cs + N);
    pq.push(Stall());
    for (int i = 0; i < N; ++i) {
        Cow &c = cs[i];
        Stall s;
        if (pq.top().end_time < c.begin) {
            s.id = pq.top().id;
            pq.pop();
        } else {
            s.id = pq.size();
        }
        s.end_time = c.end;
        pq.push(s);
        cow_to_stall[c.id] = s.id;
    }
    std::cout << pq.size() << '\n';
    for (int i = 0; i < N; ++i) {
        std::cout << cow_to_stall[i] + 1 << '\n';
    }
    return 0;
}
