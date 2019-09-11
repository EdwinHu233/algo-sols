#include <algorithm>
#include <bitset>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    visit.reset();
    visit.set(0);
    num_visit = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      for (int j : rooms[i]) {
        if (!visit[j]) {
          num_visit++;
          visit.set(j);
          q.push(j);
        }
      }
    }
    return num_visit == rooms.size();
  }

private:
  constexpr static int MAX = 1024;
  bitset<MAX> visit;
  int num_visit;
};
