#include <algorithm>
#include <cstdio>
using namespace std;

int elem[50], n;
bool newline, eof;

inline int readInt() {
  char c;
  while (true) {
    c = getchar();
    if (c == EOF) {
      eof = true;
      return 0;
    }
    if (c >= '0' && c <= '9') break;
  }
  int ans = 0;
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + (c - '0');
    c = getchar();
  }
  if (c == '\n') newline = true;
  return ans;
}

inline void flip(int x) {
  int i = x, j = n;
  while (i < j) {
    swap(elem[i], elem[j]);
    ++i, --j;
  }
}

inline bool initTest() {
  n = 0, newline = false, eof = false;
  while (true) {
    elem[++n] = readInt();
    if (eof) return false;
    if (newline) return true;
  }
}

inline int findMax(int begin) {
  int m = begin;
  for (int i = begin + 1; i <= n; ++i) {
    if (elem[i] > elem[m]) m = i;
  }
  return m;
}

inline void solve() {
  for (int i = 1; i < n; ++i) printf("%d ", elem[i]);
  printf("%d\n", elem[n]);
  flip(1);
  for (int i = 1; i <= n; ++i) {
    int m = findMax(i);
    if (m != i) {
      if (m != n) {
        flip(m);
        printf("%d ", m);
      }
      flip(i);
      printf("%d ", i);
    }
  }
  printf("0\n");
}

int main() {
  while (initTest()) solve();
  return 0;
}
