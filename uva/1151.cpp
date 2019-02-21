#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1000 + 10, Q = 8;
int n, q;

// -- define some structs
struct Edge {
  int a, b, w;
  Edge(int aa, int bb, int ww) : a(aa), b(bb), w(ww) {}
  bool operator<(const Edge &rhs) const { return w < rhs.w; }
};

struct Map {
  int city[N][2];

  vector<Edge> allEdges() {
    vector<Edge> result;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int dx = city[i][0] - city[j][0];
        int dy = city[i][1] - city[j][1];
        int dist = dx * dx + dy * dy;
        result.emplace_back(i, j, dist);
      }
    }
    return result;
  }
};

struct Subnet {
  int num, cost;
  int list[N];
};

struct Kruskal {
  struct UF {
    int pa[N];
    void reset() {
      for (int i = 0; i < N; ++i) pa[i] = i;
    }
    int root(int x) { return (pa[x] == x) ? (x) : (pa[x] = root(pa[x])); }
    bool tryUnion(int x, int y) {
      int rx = root(x), ry = root(y);
      if (rx == ry) return false;
      pa[rx] = ry;
      return true;
    }
  };
  static UF uf;

  vector<Edge> solve(vector<Edge> &es, int &cost, bool getMST) {
    vector<Edge> result;
    sort(es.begin(), es.end());
    uf.reset();
    int cnt = 0;
    for (Edge &e : es) {
      if (uf.tryUnion(e.a, e.b)) {
        cost += e.w;
        if (getMST) result.push_back(e);
        if (++cnt == n - 1) break;
      }
    }
    return result;
  }
};
Kruskal::UF Kruskal::uf;  // crazy shit of c++
// -- done

// -- global variables
Map map;
Subnet subnet[Q];
Kruskal kruskal;
// -- done

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    // init
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
      Subnet &s = subnet[i];
      cin >> s.num >> s.cost;
      for (int j = 0; j < s.num; ++j) {
        cin >> s.list[j];
      }
    }
    for (int i = 1; i <= n; ++i) {
      auto &c = map.city[i];
      cin >> c[0] >> c[1];
    }
    // MST on the original graph
    int minCost = 0;
    auto es = map.allEdges();
    es = kruskal.solve(es, minCost, true);
    // Try possible purchasing plans
    for (int mask = 1; mask < (1 << q); ++mask) {
      auto es2 = es;
      int cost = 0;
      // Add subnet 'i'
      for (int i = 0; i < q; ++i) {
        if (mask & (1 << i)) {
          auto &s = subnet[i];
          cost += s.cost;
          for (int j = 0; j < s.num; ++j) {
            for (int k = j + 1; k < s.num; ++k) {
              es2.emplace_back(s.list[j], s.list[k], 0);
            }
          }
        }
      }
      // run kruskal
      kruskal.solve(es2, cost, false);
      minCost = min(minCost, cost);
    }
    cout << minCost << '\n';
    if (T != 0) cout << '\n';
  }
  return 0;
}
