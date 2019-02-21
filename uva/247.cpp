#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 30;
bool graph[N][N];
bool printed[N];
unordered_map<string, int> id_cache;
vector<string> name_cache;

void reset() {
  memset(graph, 0, sizeof(graph));
  memset(printed, 0, sizeof(printed));
  id_cache.clear();
  name_cache.clear();
}

int get_id(const string &name) {
  if (!id_cache.count(name)) {
    name_cache.push_back(name);
    id_cache[name] = name_cache.size() - 1;
  }
  return id_cache[name];
}

void floyd(int n) {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
}

void print(int i, int n, bool is_first = true) {
  if (printed[i] || id_cache.empty()) return;
  if (!is_first) cout << ", ";
  cout << name_cache[i];
  printed[i] = true;
  for (int j = 0; j < n; ++j)
    if (graph[i][j] && graph[j][i] && !printed[j]) print(j, n, false);
  if (is_first) cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, cnt = 0;
  string a, b;
  while (cin >> n >> m && n) {
    if (cnt != 0) cout << '\n';
    cout << "Calling circles for data set " << ++cnt << ":\n";
    reset();
    while (m--) {
      cin >> a >> b;
      graph[get_id(a)][get_id(b)] = true;
    }
    floyd(n);
    for (int i = 0; i < n; ++i) print(i, n);
  }
  return 0;
}
