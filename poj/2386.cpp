#include <iostream>
using namespace std;

const int N = 105;
char garden[N][N];
bool visit[N][N];
int n, m;

void dfs(int i, int j) {
  for (int di = -1; di <= 1; ++di) {
    for (int dj = -1; dj <= 1; ++dj) {
      if (di == 0 && dj == 0) continue;
      int ii = i + di, jj = j + dj;
      if (ii >= 0 && ii < n && jj >= 0 && jj < m && garden[ii][jj] == 'W' &&
          !visit[ii][jj]) {
        visit[ii][jj] = true;
        dfs(ii, jj);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> garden[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (garden[i][j] == 'W' && !visit[i][j]) {
        ++cnt;
        visit[i][j] = true;
        dfs(i, j);
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
