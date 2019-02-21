#include <bitset>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 256;

vector<int> g[N];  // the reduced graph
queue<int> q[2];
bitset<N * N * N> visit[2];
int level;
int endpoint[2];

inline int encode(int a, int b, int c) { return (a << 16) + (b << 8) + c; }

inline void decode(int state, int &a, int &b, int &c) {
  a = (state >> 16) & 0xFF;
  b = (state >> 8) & 0xFF;
  c = state & 0xFF;
}

bool init() {
  int w, h, n;
  scanf("%d%d%d", &w, &h, &n);
  if (w == 0) return false;
  int numEmpty = 0;
  bool isEmpty[16][16];
  int id[16][16];
  int s[3], d[3];
  memset(s, 0, sizeof(s));
  memset(d, 0, sizeof(d));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char tmp = getchar();
      if (tmp == '#') {
        isEmpty[i][j] = false;
      } else {
        ++numEmpty;
        isEmpty[i][j] = true;
        id[i][j] = numEmpty;
        if (islower(tmp)) {
          s[tmp - 'a'] = numEmpty;
        } else if (isupper(tmp)) {
          d[tmp - 'A'] = numEmpty;
        }
      }
    }
    getchar();
  }
  endpoint[0] = encode(s[0], s[1], s[2]);
  endpoint[1] = encode(d[0], d[1], d[2]);
  for (int i = 0; i <= numEmpty; ++i) {
    g[i].clear();
    g[i].push_back(i);
  }
  int di[] = {0, 1, 0, -1};
  int dj[] = {1, 0, -1, 0};
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!isEmpty[i][j]) continue;
      int id1 = id[i][j];
      for (int k = 0; k < 4; ++k) {
        int ii = i + di[k], jj = j + dj[k];
        if (ii >= 0 && ii < h && jj >= 0 && jj < w && isEmpty[ii][jj]) {
          int id2 = id[ii][jj];
          g[id1].push_back(id2);
          g[id2].push_back(id1);
        }
      }
    }
  }
  for (int i = 0; i < 2; ++i) {
    q[i] = queue<int>();
    visit[i].reset();
    q[i].push(endpoint[i]);
    visit[i][endpoint[i]] = true;
  }
  level = 0;
  return true;
}

inline bool isGood(int old1, int old2, int new1, int new2) {
  if (old1 == 0 || old2 == 0) return true;
  if (new1 == new2) return false;
  if (old1 == new2 && old2 == new1) return false;
  return true;
}

bool bfsOneStep(int i) {
  int sz = q[i].size();
  while (sz--) {
    int cur = q[i].front();
    q[i].pop();
    if (visit[1 - i][cur]) return true;
    int a, b, c;
    decode(cur, a, b, c);
    for (int aa : g[a]) {
      for (int bb : g[b]) {
        for (int cc : g[c]) {
          if (!isGood(a, b, aa, bb)) continue;
          if (!isGood(b, c, bb, cc)) continue;
          if (!isGood(c, a, cc, aa)) continue;
          int code = encode(aa, bb, cc);
          if (!visit[i][code]) {
            q[i].push(code);
            visit[i][code] = true;
          }
        }
      }
    }
  }
  ++level;
  return false;
}

int main() {
  while (init()) {
    while (true) {
      int i = (q[0].size() < q[1].size()) ? 0 : 1;
      if (bfsOneStep(i)) {
        printf("%d\n", level);
        break;
      }
    }
  }
  return 0;
}
