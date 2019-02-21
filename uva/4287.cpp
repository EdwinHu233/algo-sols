#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

const int N = 20010, M = 50010;
// graph
int n, edge_cnt;
int fe[N], ne[M];  // id of edge starts at 1
int to[M];         // reset automatically
// scc
int clk, scc_cnt;
int pre[N], scc_no[N];  // start at 1
stack<int> stk;
bitset<N> has_in, has_out;

void reset() {
  edge_cnt = 0;
  memset(fe, 0, sizeof(fe));
  memset(to, 0, sizeof(to));
  clk = scc_cnt = 0;
  memset(pre, 0, sizeof(pre));
  memset(scc_no, 0, sizeof(scc_no));
  has_in.reset();
  has_out.reset();
}

void add_edge(int u, int v) {
  ++edge_cnt;
  ne[edge_cnt] = fe[u];
  fe[u] = edge_cnt;
  to[edge_cnt] = v;
}

int dfs(int u) {
  int lowu = pre[u] = ++clk;
  stk.push(u);
  for (int e = fe[u]; e; e = ne[e]) {
    int v = to[e];
    if (!pre[v]) {
      int lowv = dfs(v);
      lowu = min(lowu, lowv);
    } else if (!scc_no[v]) {
      lowu = min(lowu, pre[v]);
    }
  }
  if (lowu == pre[u]) {
    ++scc_cnt;
    while (true) {
      int v = stk.top();
      stk.pop();
      scc_no[v] = scc_cnt;
      if (v == u) break;
    }
  }
  return lowu;
}

int calculate() {
  if (scc_cnt == 1) return 0;
  for (int u = 1; u <= n; ++u) {
    for (int e = fe[u]; e; e = ne[e]) {
      int v = to[e];
      if (scc_no[u] == scc_no[v]) continue;
      has_out[scc_no[u]] = true;
      has_in[scc_no[v]] = true;
    }
  }
  int a = 0, b = 0;
  for (int i = 1; i <= scc_cnt; ++i) {
    if (!has_in[i]) ++a;
    if (!has_out[i]) ++b;
  }
  return max(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cases, m;
  int u, v;
  cin >> cases;
  while (cases--) {
    reset();
    cin >> n >> m;
    while (m--) {
      cin >> u >> v;
      add_edge(u, v);
    }
    for (int u = 1; u <= n; ++u) {
      if (!pre[u]) dfs(u);
    }
    cout << calculate() << '\n';
  }
  return 0;
}
