#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 102, M = N * N / 2;

struct Edge {
    int from, to, cost;
    bool operator<(const Edge &rhs) const { return cost < rhs.cost; }
};

struct UF {
    int id[M];
    void reset() {
        for (int i = 0; i < M; ++i) id[i] = i;
    }
    int find(int x) { return (id[x] == x) ? x : (id[x] = find(id[x])); }
    void unite(int x, int y) { id[find(x)] = find(y); }
};

Edge es[M];
int g[N][N];
int n, en;
UF uf;

bool init() {
    if (scanf("%d", &n) == EOF) return false;
    en = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Edge &e = es[en++];
            e.from = i;
            e.to = j;
            e.cost = g[i][j];
        }
    }
    return true;
}

int kruskal() {
    uf.reset();
    sort(es, es + en);
    int ans = 0;
    for (int i = 0; i < en; ++i) {
        Edge &e = es[i];
        if (uf.find(e.from) != uf.find(e.to)) {
            ans += e.cost;
            uf.unite(e.from, e.to);
        }
    }
    return ans;
}

int main() {
    while (init()) {
        printf("%d\n", kruskal());
    }
    return 0;
}
