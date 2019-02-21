#include <cstdio>
#include <vector>
using namespace std;

struct Node {
  double lenL, lenR;
  Node() : lenL(0), lenR(0) {}
};

const int N = 6;
int n;
double maxLen;
double weight[N];
// info for every subset
bool visit[1 << N];
double sum[1 << N];
vector<Node> ns[1 << N];  // ns[subset] contains all possibilities of 'subset'

void init() {
  scanf("%lf%d", &maxLen, &n);
  for (int i = 0; i < n; ++i) scanf("%lf", weight + i);
  for (int i = 0; i < (1 << n); ++i) {
    visit[i] = false;
    sum[i] = 0;
    ns[i].clear();
    for (int j = 0; j < n; ++j) {
      if ((1 << j) & i) sum[i] += weight[j];
    }
  }
}

void solve(int cur) {
  if (visit[cur]) return;
  visit[cur] = true;
  if (cur & (cur - 1)) {  // 'cur' contains more than one element
    // 'left' and 'right' are strict subsets of 'cur'
    for (int left = (cur - 1) & cur; left; left = (left - 1) & cur) {
      int right = cur - left;
      solve(left);
      solve(right);
      double curL = sum[right] / (sum[left] + sum[right]),
             curR = sum[left] / (sum[left] + sum[right]);
      for (auto &nl : ns[left]) {
        for (auto &nr : ns[right]) {
          Node tmp;
          tmp.lenL = max(nl.lenL + curL, nr.lenL - curR);
          tmp.lenR = max(nr.lenR + curR, nl.lenR - curL);
          if (tmp.lenL + tmp.lenR < maxLen) ns[cur].push_back(tmp);
        }
      }
    }
  } else {  // 'cur' has a single element
    ns[cur].emplace_back();
  }
}

int main() {
  int numCases;
  scanf("%d", &numCases);
  while (numCases--) {
    init();
    int root = (1 << n) - 1;
    solve(root);
    double ans = -1;
    for (auto &n : ns[root]) ans = max(ans, n.lenL + n.lenR);
    printf("%.10lf\n", ans);
  }
}
