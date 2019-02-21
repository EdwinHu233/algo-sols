#include <cstring>
#include <iostream>
using namespace std;

const int N = 26;
int num_edge[N][N];
int id[N], degree[2][N];

void reset() {
  memset(num_edge, 0, sizeof(num_edge));
  for (int i = 0; i < N; ++i) id[i] = i;
  memset(degree, 0, sizeof(degree));
}

int Find(int x) { return (id[x] == x) ? x : (id[x] = Find(id[x])); }

void Union(int x, int y) { id[Find(x)] = Find(y); }

bool check() {
  // Loop through all edges.
  // Calculate in/out -degrees and union adjecent nodes.
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (num_edge[i][j] > 0) {
        degree[0][i] += num_edge[i][j];
        degree[1][j] += num_edge[i][j];
        Union(i, j);
      }
    }
  }
  // For non-isolated nodes, check if they are
  // in the same conncected component, and if the
  // difference of in/out -degrees is -1, 1, or 0.
  bool plus1 = false, minus1 = false;
  int last_id = -1;
  for (int i = 0; i < N; ++i) {
    if (degree[0][i] > 0 || degree[1][i] > 0) {
      int d = degree[0][i] - degree[1][i];
      if (d == -1 && !minus1) {
        minus1 = true;
      } else if (d == 1 && !plus1) {
        plus1 = true;
      } else if (d != 0) {
        return false;
      }
      if (last_id == -1) last_id = Find(i);
      if (last_id != Find(i)) return false;
    }
  }
  return true;
}

int main() {
  int cases;
  string buffer;
  cin >> cases;
  while (cases--) {
    int num_word;
    cin >> num_word;
    reset();
    while (num_word--) {
      cin >> buffer;
      int a = buffer[0] - 'a', b = buffer.back() - 'a';
      num_edge[a][b]++;
    }
    cout << (check() ? "Ordering is possible.\n"
                     : "The door cannot be opened.\n");
  }
  return 0;
}
