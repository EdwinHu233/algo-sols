#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
    G.clear();
    G.resize(N);
    ans.resize(N);
    fill(ans.begin(), ans.end(), 0);
    for (const auto &p : paths) {
      int a = p[0] - 1, b = p[1] - 1;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    backtrace(0, N);
    return ans;
  }

private:
  inline bool id_is_available(int i, int id) {
    for (int j : G[i]) {
      if (ans[j] == id) {
        return false;
      }
    }
    return true;
  }

  inline bool backtrace(const int i, const int N) {
    if (i == N) {
      return true;
    }
    for (int id = 1; id <= 4; ++id) {
      if (id_is_available(i, id)) {
        ans[i] = id;
        if (backtrace(i + 1, N)) {
          return true;
        }
      }
    }
    ans[i] = 0;
    return false;
  }

  vector<vector<int>> G;
  vector<int> ans;
};
