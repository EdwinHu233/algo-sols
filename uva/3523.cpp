#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int N = 1005;

// Graph
int n;
bitset<N> hate[N];
// BCC
int clk, num_bcc;
bitset<N> bcc[N];
int pre[N];
stack<pair<int, int>> s;
// Bipartition
int color[N];
bitset<N> odd;

void reset() {
  // 'color' should be reset for every BCC.
  // Other variables should be reset for every test case.
  for (int i = 0; i < n; ++i) hate[i] = 0;
  clk = num_bcc = 0;
  for (int i = 0; i < n; ++i) bcc[i] = 0;
  memset(pre, 0, sizeof(pre));
  odd = 0;
}

int dfs(int u, int p) {
  int lowu = pre[u] = ++clk;
  for (int v = 0; v < n; ++v) {
    if (hate[u][v] || u == v) continue;
    // v is one of u's neighbors
    if (!pre[v]) {  // v is u's child, since v hasn't been visited
      s.push(make_pair(u, v));
      int lowv = dfs(v, u);
      lowu = min(lowu, lowv);
      if (lowv >= pre[u]) {  // u is a cut vertex
        auto &b = bcc[num_bcc++];
        while (true) {
          auto x = s.top().first, y = s.top().second;
          s.pop();
          b[x] = b[y] = true;
          if (x == u && y == v) break;
        }
      }
    } else if (pre[v] < pre[u] && v != p) {  // v is u's ancestor
      s.push(make_pair(u, v));
      lowu = min(lowu, pre[v]);
    }
  }
  return lowu;
}

void find_bcc(int n) {
  for (int i = 0; i < n; ++i) {
    if (!pre[i]) dfs(i, -1);
  }
}

bool bipartite(bitset<N> &b) {
  memset(color, 0, sizeof(color));
  queue<int> q;
  int u = 0;
  while (!b[u]) ++u;
  q.push(u);
  color[u] = 1;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int v = 0; v < n; ++v) {
      if (!b[v] || hate[u][v] || v == u) continue;
      // v is a neighbor of u. And they belong to the same BCC
      if (color[u] == color[v]) return false;
      if (!color[v]) {
        color[v] = 3 - color[u];
        q.push(v);
      }
    }
  }
  return true;
}

void find_odd() {
  for (int i = 0; i < num_bcc; ++i) {
    if (bipartite(bcc[i])) continue;
    for (int j = 0; j < n; ++j) {
      if (bcc[i][j]) odd[j] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, u, v;
  while (cin >> n >> m && n) {
    reset();
    while (m--) {
      cin >> u >> v;
      --u, --v;  // ID of nodes should start at 0.
      hate[u][v] = hate[v][u] = true;
    }
    find_bcc(n);
    find_odd();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!odd[i]) ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}
