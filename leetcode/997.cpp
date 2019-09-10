#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    memset(id, 0, sizeof(id));
    memset(od, 0, sizeof(od));
    for (const auto &t : trust) {
      int a = t[0], b = t[1];
      od[a]++;
      id[b]++;
    }
    int ans = -1;
    for (int i = 1; i <= N; ++i) {
      if (od[i] == 0 && id[i] == N - 1) {
        if (ans < 0) {
          ans = i;
        } else {
          return -1;
        }
      }
    }
    return ans;
  }

private:
  constexpr static int MAX = 10000;
  int id[MAX], od[MAX];
};
