#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100 + 10, M = 5000;
int n, m;

struct Edge {
  int a, b, w;
  bool operator<(const Edge &rhs) const { return w < rhs.w; }
} es[M];

struct UF {
  int parent[N];

  void reset() {
    for (int i = 0; i < N; ++i) parent[i] = i;
  }

  int root(int x) {
    return (parent[x] == x) ? (x) : (parent[x] = root(parent[x]));
  }

  void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    parent[rx] = ry;
  }
} uf;

bool readGraph() {
  cin >> n >> m;
  if (n == 0) return false;
  for (int i = 0; i < m; ++i) {
    cin >> es[i].a >> es[i].b >> es[i].w;
  }
  sort(es, es + m);
  return true;
}

int solve() {
  int slim = INT32_MAX;
  for (int i = 0; i < m; ++i) {
    int cnt = 0;
    uf.reset();
    for (int j = i; j < m; ++j) {
      Edge &e = es[j];
      if (uf.root(e.a) != uf.root(e.b)) {
        uf.unite(e.a, e.b);
        ++cnt;
        if (cnt == n - 1) {
          slim = min(slim, e.w - es[i].w);
          break;
        }
      }
    }
  }
  return (slim == INT32_MAX) ? -1 : slim;
}

int main() {
  ios_base::sync_with_stdio(false);
  while (readGraph()) {
    cout << solve() << '\n';
  }
  return 0;
}
