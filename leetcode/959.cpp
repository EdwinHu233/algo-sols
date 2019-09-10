#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    int N = grid.size();
    uf.reset(grid.size());
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        uf.unite_by_char(i, j, grid[i][j]);
      }
    }
    return uf.num_uf;
  }

private:
  struct UF {
    constexpr static int MAX = 30;
    int N, num_uf;
    int pa[MAX * MAX * 4];

    inline int id(int row, int col, int i) { return (row * N + col) * 4 + i; }

    void reset(int N) {
      this->N = N;
      num_uf = N * N * 4;
      for (int i = 0; i < num_uf; ++i) {
        pa[i] = i;
      }
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (i != 0)
            unite(id(i - 1, j, 2), id(i, j, 0));
          if (j != 0)
            unite(id(i, j - 1, 1), id(i, j, 3));
        }
      }
    }

    int root(int i) {
      if (pa[i] != i) {
        pa[i] = root(pa[i]);
      }
      return pa[i];
    }

    void unite(int i, int j) {
      int ri = root(i), rj = root(j);
      if (ri != rj) {
        pa[ri] = rj;
        --num_uf;
      }
    }

    void unite_by_char(int row, int col, char c) {
      int i = id(row, col, 0);
      if (c == ' ') {
        unite(i, i + 1);
        unite(i, i + 2);
        unite(i, i + 3);
      } else if (c == '/') {
        unite(i, i + 3);
        unite(i + 1, i + 2);
      } else {
        unite(i, i + 1);
        unite(i + 2, i + 3);
      }
    }
  } uf;
};
