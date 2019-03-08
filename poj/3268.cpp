#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};

const int N = 1000 + 10;
const int INF = 100000000;

int n, m, x;
vector<Edge> graph[2][N];
int dist[2][N];

void init() {
    scanf("%d%d%d", &n, &m, &x);
    --x;
    while (m--) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        --a, --b;
        graph[0][a].push_back(Edge(b, t));
        graph[1][b].push_back(Edge(a, t));
    }
}

void dijkstra(int i) {
    fill(dist[i], dist[i] + n, INF);
    dist[i][x] = 0;
    typedef pair<int, int> P;  // (d, u)
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P(0, x));
    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (dist[i][u] < d) continue;
        for (unsigned j = 0; j < graph[i][u].size(); ++j) {
            Edge &e = graph[i][u][j];
            if (d + e.cost < dist[i][e.to]) {
                dist[i][e.to] = d + e.cost;
                q.push(P(dist[i][e.to], e.to));
            }
        }
    }
}

int main() {
    init();
    dijkstra(0);
    dijkstra(1);
    for (int i = 0; i < n; ++i) dist[0][i] += dist[1][i];
    printf("%d\n", *max_element(dist[0], dist[0] + n));
    return 0;
}
