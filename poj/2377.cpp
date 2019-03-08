#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1000 + 5, M = 20000 + 5;

struct UF {
    int id[N];
    void reset() {
        for (int i = 0; i < N; ++i) {
            id[i] = i;
        }
    }
    int find(int x) { return (id[x] == x) ? x : (id[x] = find(id[x])); }
    void unite(int x, int y) { id[find(x)] = find(y); }
};

struct Edge {
    int a, b, cost;
    bool operator<(const Edge &rhs) const { return cost > rhs.cost; }
};

UF uf;
Edge es[M];
int n, m;

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        Edge &e = es[i];
        scanf("%d%d%d", &e.a, &e.b, &e.cost);
    }
}

int kruskal() {
    uf.reset();
    sort(es, es + m);
    int sum = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        Edge &e = es[i];
        if (uf.find(e.a) != uf.find(e.b)) {
            uf.unite(e.a, e.b);
            ++cnt;
            sum += e.cost;
        }
    }
    return (cnt == n - 1) ? sum : -1;
}

int main() {
    init();
    printf("%d\n", kruskal());
    return 0;
}
