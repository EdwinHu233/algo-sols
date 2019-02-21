#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 20, M = 100;
using Bits = uint32_t;

struct Patch {
  Bits must, mustNot;
  Bits add, fix;
  int cost;

  bool match(Bits status) const {
    if ((must | status) != status) return false;
    if ((mustNot & status) != 0) return false;
    return true;
  }

  Bits apply(Bits status) const {
    status |= add;
    status &= ~fix;
    return status;
  }
};

struct HeapNode {
  Bits status;
  int dist;
  HeapNode(Bits s, int d) : status(s), dist(d) {}
  bool operator<(const HeapNode &rhs) const { return dist > rhs.dist; }
};

int n, m;
Patch ps[M];
bitset<1 << N> done;
int minDist[1 << N];

bool init() {
  if (cin >> n >> m && n != 0) {
    memset(ps, 0, sizeof(ps));
    string tmp;
    for (int i = 0; i < m; ++i) {
      Patch &p = ps[i];
      cin >> p.cost;
      cin >> tmp;
      for (int j = 0; j < n; ++j) {
        if (tmp[j] == '+') {
          p.must |= (1 << j);
        } else if (tmp[j] == '-') {
          p.mustNot |= (1 << j);
        }
      }
      cin >> tmp;
      for (int j = 0; j < n; ++j) {
        if (tmp[j] == '+') {
          p.add |= (1 << j);
        } else if (tmp[j] == '-') {
          p.fix |= (1 << j);
        }
      }
    }
    return true;
  } else {
    return false;
  }
}

int dijkstra() {
  memset(minDist, -1, sizeof(minDist));
  done.reset();
  priority_queue<HeapNode> pq;
  const Bits src = (1 << n) - 1, dst = 0;
  pq.push(HeapNode(src, 0));
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (cur.status == dst) return cur.dist;
    if (done[cur.status]) continue;
    done[cur.status] = true;
    for (int i = 0; i < m; ++i) {
      if (!ps[i].match(cur.status)) continue;
      Bits b = ps[i].apply(cur.status);
      int d = cur.dist + ps[i].cost;
      if (minDist[b] < 0 || d < minDist[b]) {
        minDist[b] = d;
        pq.push(HeapNode(b, d));
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  int i = 0;
  while (init()) {
    int result = dijkstra();
    cout << "Product " << (++i) << '\n';
    if (result < 0) {
      cout << "Bugs cannot be fixed.\n\n";
    } else {
      cout << "Fastest sequence takes " << result << " seconds.\n\n";
    }
  }
  return 0;
}
