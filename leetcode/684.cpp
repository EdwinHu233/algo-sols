#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    auto N = edges.size();
    uf.reset(N);
    for (const auto &e : edges) {
      if (!uf.unite(e[0], e[1])) {
        return e;
      }
    }
    return edges.back(); // dumb statement to make the compiler happy
  }

private:
  struct UF {
    using u16 = uint16_t;
    constexpr static int MAX = 1024;
    u16 pa[MAX];

    void reset(u16 N) {
      for (u16 i = 1; i <= N; ++i) {
        pa[i] = i;
      }
    }

    u16 root(u16 i) { return (pa[i] == i) ? (i) : (pa[i] = root(pa[i])); }

    bool unite(u16 i, u16 j) {
      u16 ri = root(i), rj = root(j);
      if (ri != rj) {
        pa[ri] = rj;
        return true;
      }
      return false;
    }
  } uf;
};
