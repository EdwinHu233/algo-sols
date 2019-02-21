#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

const int N = 1010;
// graph
int n;
bitset<N> g[N];
// scc
int clk, scc_cnt;
int pre[N], scc_no[N];
stack<int> stk;
// calculating
bitset<N> scc[N];
int num[N], max_weight[N];

void reset() {
  for (int i = 0; i < N; ++i) g[i].reset();
  clk = scc_cnt = 0;
  memset(pre, 0, sizeof(pre));
  memset(scc_no, 0, sizeof(scc_no));
  for (int i = 0; i < N; ++i) scc[i].reset();
  memset(num, 0, sizeof(num));
  memset(max_weight, 0, sizeof(max_weight));
}

int dfs(int u) {
  int lowu = pre[u] = ++clk;
  stk.push(u);
  for (int v = 0; v < n; ++v) {
    if (!g[u][v]) continue;
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

void find_scc() {
  for (int u = 0; u < n; ++u)
    if (!pre[u]) dfs(u);
}

void construct_scc() {
  for (int u = 0; u < n; ++u) {
    int i = scc_no[u];
    ++num[i];
    for (int v = 0; v < n; ++v) {
      int j = scc_no[v];
      if (g[u][v] && i != j) scc[i][j] = true;
    }
  }
}

void calculate(int i) {
  if (max_weight[i]) return;
  max_weight[i] = num[i];
  if (scc[i].none()) return;
  int descendant = 0;
  for (int j = 1; j <= scc_cnt; ++j) {
    if (scc[i][j] && i != j) {
      calculate(j);
      descendant = max(descendant, max_weight[j]);
    }
  }
  max_weight[i] += descendant;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cases, m, u, v;
  cin >> cases;
  while (cases--) {
    reset();
    cin >> n >> m;
    while (m--) {
      cin >> u >> v;
      g[u - 1][v - 1] = true;
    }
    find_scc();
    construct_scc();
    int ans = 0;
    for (int i = 1; i <= scc_cnt; ++i) {
      calculate(i);
      ans = max(ans, max_weight[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
