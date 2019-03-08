#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 500, M = 2500, W = 200;

struct Edge {
    int from, to, cost;
};

int ds[N + 5];
Edge es[M * 2 + W + 5];
int vn, en;

void add_edge(int from, int to, int cost) {
    Edge &e = es[en++];
    e.from = from;
    e.to = to;
    e.cost = cost;
}

void init() {
    int m, w;
    scanf("%d%d%d", &vn, &m, &w);
    int from, to, cost;
    en = 0;
    while (m--) {
        scanf("%d%d%d", &from, &to, &cost);
        add_edge(from, to, cost);
        add_edge(to, from, cost);
    }
    while (w--) {
        scanf("%d%d%d", &from, &to, &cost);
        add_edge(from, to, -cost);
    }
}

bool has_negative_loop() {
    memset(ds, 0, sizeof(ds));
    for (int i = 0; i < vn; ++i) {
        for (int j = 0; j < en; ++j) {
            Edge &e = es[j];
            if (ds[e.to] > ds[e.from] + e.cost) {
                ds[e.to] = ds[e.from] + e.cost;
                if (i == vn - 1) return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        printf(has_negative_loop() ? "YES\n" : "NO\n");
    }
    return 0;
}
