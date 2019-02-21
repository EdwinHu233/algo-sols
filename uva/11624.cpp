#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
  unsigned row, col;
  Pos(unsigned r, unsigned c) : row(r), col(c) {}
  Pos go(int i) {
    const static int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
    return Pos(row + dr[i], col + dc[i]);
  }
};

class Maze {
  unsigned R, C;
  const static unsigned N = 1005;
  bool _block[N][N];
  unsigned _time_arrive[N][N];
  unsigned _time_burn[N][N];

  inline bool in_maze(const Pos &p) { return p.row < R && p.col < C; }
  inline bool &block(const Pos &p) { return _block[p.row][p.col]; }
  inline unsigned &time_burn(const Pos &p) { return _time_burn[p.row][p.col]; }
  inline unsigned &time_arrive(const Pos &p) {
    return _time_arrive[p.row][p.col];
  }

  void reset() {
    memset(_block, 0, sizeof(_block));
    memset(_time_arrive, -1, sizeof(_time_arrive));
    memset(_time_burn, -1, sizeof(_time_burn));
  }

  void set_time_burn(queue<Pos> &q) {
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        auto v = u.go(i);
        if (in_maze(v) && !block(v) && time_burn(v) > time_burn(u) + 1) {
          time_burn(v) = time_burn(u) + 1;
          q.push(v);
        }
      }
    }
  }

  int escape(Pos src) {
    queue<Pos> q;
    q.push(src);
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      auto t = time_arrive(u) + 1;
      for (int i = 0; i < 4; ++i) {
        auto v = u.go(i);
        if (!in_maze(v)) return t;
        if (block(v) || time_burn(v) <= t || time_arrive(v) <= t) continue;
        time_arrive(v) = t;
        q.push(v);
      }
    }
    return -1;
  }

 public:
  int solve(int num_row, int num_col) {
    reset();
    R = num_row, C = num_col;
    queue<Pos> q;
    string buffer;
    int r, c;
    for (unsigned i = 0; i < R; ++i) {
      cin >> buffer;
      for (unsigned j = 0; j < C; ++j) {
        switch (buffer[j]) {
          case '#':
            _block[i][j] = true;
            break;
          case 'F':
            _time_burn[i][j] = 0;
            q.push(Pos(i, j));
            break;
          case 'J':
            r = i, c = j;
            _time_arrive[r][c] = 0;
            break;
        }
      }
    }
    set_time_burn(q);
    return escape(Pos(r, c));
  }
} maze;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cases, num_row, num_col;
  cin >> cases;
  while (cases--) {
    cin >> num_row >> num_col;
    auto result = maze.solve(num_row, num_col);
    if (result < 0) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << result << '\n';
    }
  }
  return 0;
}
