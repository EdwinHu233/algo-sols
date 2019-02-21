#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int N = 26;
bool G[N][N], occur[N];
int pos[N], seq[N], optSeq[N];  // 'seq' and 'optSeq' needn't be initialized
int curBandwith, optBandwith, n;

void init(const string &line) {
  memset(G, 0, sizeof(G));
  memset(occur, 0, sizeof(occur));
  memset(pos, -1, sizeof(pos));
  curBandwith = 0;
  optBandwith = 1000000;
  n = 0;
  bool newNode = true;
  int u, v;
  for (char c : line) {
    if (isalpha(c)) {
      if (!occur[c - 'A']) {
        occur[c - 'A'] = true;
        ++n;
      }
      if (newNode) {
        u = c - 'A';
        newNode = false;
      } else {
        v = c - 'A';
        G[u][v] = G[v][u] = true;
      }
    } else if (c == ';') {
      newNode = true;
    }
  }
}

pair<int, int> getInfo(const int u) {
  int maxDist = 0, undetermined = 0;
  for (int v = 0; v < N; ++v) {
    if (occur[v] && G[u][v]) {
      if (pos[v] >= 0) {
        maxDist = max(maxDist, abs(pos[u] - pos[v]));
      } else {
        ++undetermined;
      }
    }
  }
  return make_pair(maxDist, undetermined);
}

void dfs(const int cur) {
  if (cur == n) {
    if (curBandwith < optBandwith) {
      optBandwith = curBandwith;
      for (int i = 0; i < n; ++i) optSeq[i] = seq[i];
    }
    return;
  }
  for (int i = 0; i < N; ++i) {
    if (occur[i] && pos[i] < 0) {
      pos[i] = cur;
      seq[cur] = i;
      auto p = getInfo(i);
      if (p.first < optBandwith && p.second < optBandwith) {
        int oldCurBW = curBandwith;
        curBandwith = max(curBandwith, p.first);
        dfs(cur + 1);
        curBandwith = oldCurBW;
      }
      pos[i] = -1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  string line;
  while (getline(cin, line) && line[0] != '#') {
    init(line);
    dfs(0);
    for (int i = 0; i < n; ++i) {
      cout << char(optSeq[i] + 'A') << ' ';
    }
    cout << "-> " << optBandwith << '\n';
  }
}
