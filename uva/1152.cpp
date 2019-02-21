#include <algorithm>
#include <cstdio>
#include <unordered_map>
using namespace std;

const int N = 4000 + 10;
int a[N], b[N], c[N], d[N];
unordered_map<int, int> sumAB;

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
    }
    sumAB.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int sum = a[i] + b[j];
        if (sumAB.find(sum) == sumAB.end())
          sumAB[sum] = 1;
        else
          sumAB[sum] += 1;
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int sum = c[i] + d[j];
        auto it = sumAB.find(-sum);
        if (it != sumAB.end()) cnt += it->second;
      }
    }
    printf("%d\n", cnt);
    if (T) printf("\n");
  }
  return 0;
}
