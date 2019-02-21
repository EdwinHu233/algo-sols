#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 50000 + 10;
int n;

// Graph
int cnt_e;
int fe[N], ne[N];
int to[N];  // automatically reset

// BCC
int clk, cnt_bcc;
int pre[N];
bitset<N> is_cut;
bitset<N> in_bcc;           // lazy reset
vector<int> bcc[N];         // lazy reset
stack<pair<int, int>> stk;  // automatically reset

void reset() {
  cnt_e = 0;
  memset(fe, -1, sizeof(fe));
  memset(ne, -1, sizeof(ne));
  clk = cnt_bcc = 0;
  memset(pre, 0, sizeof(pre));
  is_cut = 0;
}

void add_edge(int u, int v, bool repeat = true) {
  ne[cnt_e] = fe[u];
  fe[u] = cnt_e;
  to[cnt_e] = v;
  ++cnt_e;
  if (repeat) add_edge(v, u, false);
}

void add_to_bcc(int u) {
  if (in_bcc[u]) return;
  in_bcc[u] = true;
  bcc[cnt_bcc - 1].push_back(u);
}

int dfs(int u, int p) {
  int lowu = pre[u] = ++clk;
  int child = 0;
  for (int e = fe[u]; e >= 0; e = ne[e]) {
    int v = to[e];
    if (!pre[v]) {  // v is a child of u.
      ++child;
      stk.push(make_pair(u, v));
      int lowv = dfs(v, u);
      lowu = min(lowu, lowv);
      if (lowv >= pre[u]) {  // u is a cut vertex.
        is_cut[u] = true;
        bcc[cnt_bcc++].clear();
        in_bcc = 0;
        while (true) {
          auto x = stk.top().first, y = stk.top().second;
          stk.pop();
          add_to_bcc(x);
          add_to_bcc(y);
          if (x == u && y == v) break;
        }
      }
    } else if (pre[v] < pre[u] && v != p) {
      lowu = min(lowu, pre[v]);
      stk.push(make_pair(u, v));
    }
  }
  if (p < 0 && child == 1) is_cut[u] = false;
  return lowu;
}

void find_bcc() {
  for (int i = 0; i < n; ++i) {
    if (!pre[i]) dfs(i, -1);
  }
}

pair<uint64_t, uint64_t> calculate() {
  if (cnt_bcc == 1) return make_pair(2, n * (n - 1) / 2);
  uint64_t ans1 = 0, ans2 = 1;
  for (int i = 0; i < cnt_bcc; ++i) {
    int cut = 0;
    for (int u : bcc[i]) {
      if (is_cut[u]) ++cut;
    }
    if (cut == 1) {
      ans1++;
      ans2 *= bcc[i].size() - 1;
    }
  }
  return make_pair(ans1, ans2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, u, v;
  int cases = 0;
  while (cin >> m && m) {
    cout << "Case " << ++cases << ": ";
    reset();
    n = 0;
    while (m--) {
      cin >> u >> v;
      n = max(n, u);
      n = max(n, v);
      add_edge(u - 1, v - 1);
    }
    find_bcc();
    auto ans = calculate();
    cout << ans.first << ' ' << ans.second << '\n';
  }
  return 0;
}
