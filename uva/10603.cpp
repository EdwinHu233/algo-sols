#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int CAPACITY = 200 + 1;
int capacity[3];
bool visit[CAPACITY][CAPACITY];

struct State {
  int water[3], dist;

  bool operator<(const State &rhs) const { return dist > rhs.dist; }
};

void solve(int d) {
  int approxD = 0, approxDist = 0;
  State src = (State){{0, 0, capacity[2]}, 0};
  priority_queue<State> pq;
  pq.push(src);
  while (!pq.empty()) {
    State cur = pq.top();
    pq.pop();
    for (int i = 0; i < 3; ++i) {
      if (cur.water[i] == d) {
        printf("%d %d\n", cur.dist, d);
        return;
      } else if (cur.water[i] < d && cur.water[i] > approxD) {
        approxD = cur.water[i];
        approxDist = cur.dist;
      }
    }
    for (int from = 0; from < 3; ++from) {
      for (int to = 0; to < 3; ++to) {
        if (from == to || cur.water[from] == 0 || cur.water[to] == capacity[to])
          continue;
        State tmp = cur;
        int pour = min(tmp.water[from], capacity[to] - tmp.water[to]);
        tmp.water[from] -= pour;
        tmp.water[to] += pour;
        tmp.dist += pour;
        if (!visit[tmp.water[0]][tmp.water[1]]) {
          pq.push(tmp);
          visit[tmp.water[0]][tmp.water[1]] = true;
        }
      }
    }
  }
  printf("%d %d\n", approxDist, approxD);
}

int main() {
  int numTest, d;
  scanf("%d", &numTest);
  while (numTest--) {
    scanf("%d%d%d%d", capacity + 0, capacity + 1, capacity + 2, &d);
    memset(visit, 0, sizeof(visit));
    solve(d);
  }
  return 0;
}
