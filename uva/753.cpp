#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 400 + 5;

struct Model {
  map<string, int> strToID;
  int cnt;
  bool G[N][N];

  void init() {
    strToID.clear();
    cnt = 0;
    memset(G, 0, sizeof(G));
    for (int i = 0; i < N; ++i) G[i][i] = true;
  }

  int getID(const string &s) {
    if (strToID.find(s) == strToID.end()) {
      strToID[s] = ++cnt;
    }
    return strToID[s];
  }

  void floyd() {
    for (int k = 0; k < cnt; ++k) {
      for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
          G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
        }
      }
    }
  }
} model;

struct EdmondsKarp {};
