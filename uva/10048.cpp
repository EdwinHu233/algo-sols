#include <cstring>
#include <iostream>
using namespace std;

const int N = 105;

int graph[N][N];

void reset() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      graph[i][j] = INT32_MAX;
    }
  }
}

void floyd(const int n) {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, x, y, val, q;
  int num_case = 0;
  while (cin >> n >> m >> q && n) {
    reset();
    if (num_case != 0) cout << '\n';
    cout << "Case #" << ++num_case << '\n';
    while (m--) {
      cin >> x >> y >> val;
      graph[x][y] = graph[y][x] = val;
    }
    floyd(n);
    while (q--) {
      cin >> x >> y;
      if (graph[x][y] != INT32_MAX) {
        cout << graph[x][y] << '\n';
      } else {
        cout << "no path\n";
      }
    }
  }
  return 0;
}
