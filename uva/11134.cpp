#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5000 + 10;

struct Rook {
  int left, right, ans;
};

using Rs = Rook[N];
Rs X, Y;
int n;

bool init() {
  scanf("%d", &n);
  if (n == 0) return false;
  for (int i = 0; i < n; ++i) {
    Rook &x = X[i], &y = Y[i];
    scanf("%d%d%d%d", &x.left, &y.left, &x.right, &y.right);
    x.ans = y.ans = -1;
  }
  return true;
}

bool greedy(Rs &rs) {
  for (int pos = 1; pos <= n; ++pos) {
    int bestRook = -1;
    for (int i = 0; i < n; ++i) {
      Rook &r = rs[i];
      if (r.ans >= 0 || r.left > pos || r.right < pos) continue;
      if (bestRook == -1 || r.right < rs[bestRook].right) bestRook = i;
    }
    if (bestRook == -1) return false;
    rs[bestRook].ans = pos;
  }
  return true;
}

int main() {
  while (init()) {
    if (greedy(X) && greedy(Y)) {
      for (int i = 0; i < n; ++i) {
        printf("%d %d\n", X[i].ans, Y[i].ans);
      }
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
