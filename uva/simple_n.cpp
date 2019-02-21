#include <iostream>
#include <vector>

using namespace std;

void print_permutation(int cur, int n, vector<int> &p) {
  if (cur == n) {
    for (int i = 0; i < n; ++i) cout << p[i] << ',';
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; ++i) {
    bool used = false;
    for (int j = 0; j < cur; ++j) {
      if (p[j] == i) {
        used = true;
        break;
      }
    }
    if (used) continue;
    p[cur] = i;
    print_permutation(cur + 1, n, p);
  }
}

int main() {
  int n = 5;
  vector<int> p(n);
  print_permutation(0, n, p);
  return 0;
}
