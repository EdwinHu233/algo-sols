#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2000 + 5;
const int M = 10000 + 5;

struct Edge {
    int a, b, cost;
    bool operator<(const Edge &rhs) const { return cost < rhs.cost; }
};

struct UF {
    int id[N];
    void reset() {
        for (int i = 0; i < N; ++i) id[i] = i;
    }
    int find(int x) { return (id[x] == x) ? x : (id[x] = find(id[x])); }
    void unite(int x, int y) { id[find(x)] = find(y); }
};

Edge es[M];
UF uf;
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
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        Edge &e = es[i];
        if (uf.find(e.a) != uf.find(e.b)) {
            ans = max(ans, e.cost);
            uf.unite(e.a, e.b);
        }
    }
    return ans;
}

int main() {
    init();
    printf("%d\n", kruskal());
    return 0;
}
