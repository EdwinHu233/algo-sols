#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int N = 1000 + 5;
const int L = 1000000 + 10;

struct Edge {
    int to, len;
    Edge(int t, int l) : to(t), len(l) {}
};

vector<Edge> g[N];
int dist[N];
int n, p, k;

void init() {
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 0; i < p; ++i) {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        --a, --b;
        g[a].push_back(Edge(b, l));
        g[b].push_back(Edge(a, l));
    }
}

bool C(int x) {
    typedef pair<int, int> P;  // (d, u)
    priority_queue<P, vector<P>, greater<P>> pq;
    fill(dist, dist + n, 0x7f7f7f7f);
    dist[0] = 0;
    pq.push(P(0, 0));
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dist[u] < d) continue;
        for (unsigned i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].to;
            int dd = (g[u][i].len > x ? 1 : 0) + d;
            if (dd < dist[v]) {
                dist[v] = dd;
                pq.push(P(dd, v));
            }
        }
    }
    return dist[n - 1] <= k;
}

int main() {
    init();
    int l = 0, h = L;
    while (l < h) {
        int m = (h - l) / 2 + l;
        if (C(m)) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    printf("%d\n", (l == L ? -1 : l));
}
