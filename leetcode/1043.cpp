#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &A, int K) {
    memset(x, 0, sizeof(x));
    x[0] = 0;
    int N = A.size();
    for (int n = 0; n < N; ++n) {
      int current_max = 0;
      for (int k = 1; k <= K && k + n <= N; ++k) {
        current_max = max(current_max, A[n + k - 1]);
        x[n + k] = max(x[n + k], x[n] + k * current_max);
      }
    }
    return x[N];
  }

private:
  constexpr static int MAX = 510;
  int x[MAX];
};
