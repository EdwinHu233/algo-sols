#include <iostream>
using namespace std;

const int N = 1000000;
int d[N];

int main() {
  ios_base::sync_with_stdio(false);
  int T, L, n;
  cin >> T;
  while (T--) {
    cin >> L >> n;
    for (int i = 0; i < n; ++i) {
      cin >> d[i];
    }
    int early = -1, late = -1;
    for (int i = 0; i < n; ++i) {
      early = max(early, min(d[i], L - d[i]));
      late = max(late, max(d[i], L - d[i]));
    }
    cout << early << ' ' << late << '\n';
  }
  return 0;
}
