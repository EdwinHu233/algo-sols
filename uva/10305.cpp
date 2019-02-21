#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 105;

bool has_edge[MAX][MAX];
int result[MAX];
int visited[MAX];  // -1: "being visited"
                   // 0: "not visited"
                   // 1: "been visited"

void reset() {
  memset(visited, 0, sizeof(visited));
  memset(result, 0, sizeof(result));
  memset(has_edge, 0, sizeof(has_edge));
}

bool topo_visit(const int N, int u, int &num_visited) {
  visited[u] = -1;
  for (int v = 1; v <= N; ++v) {
    // Unreachable, or in another DFS tree.
    if (!has_edge[u][v] || visited[v] == 1) continue;
    // Detect a cycle. Failed.
    if (visited[v] == -1 || !topo_visit(N, v, num_visited)) return false;
  }
  visited[u] = 1;
  result[num_visited++] = u;
  return true;
}

bool topo(const int N) {
  int num_visited = 0;
  for (int u = 1; u <= N; ++u) {
    if (visited[u] != 0) continue;                     // Visited.
    if (!topo_visit(N, u, num_visited)) return false;  // Failed.
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  while (cin >> n >> m && n) {
    reset();
    int u, v;
    while (m--) {
      cin >> u >> v;
      has_edge[u][v] = true;
    }
    topo(n);
    for (int i = n - 1; i >= 0; --i) {
      if (i != n - 1) cout << ' ';
      cout << result[i];
    }
    cout << '\n';
  }
  return 0;
}
