#include <cstring>
#include <iostream>
#include <queue>

const unsigned MAX = 300 + 5;
bool visited[MAX][MAX];
unsigned destroy[MAX][MAX];

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct Node {
    unsigned x, y, t;
    Node(int xx, int yy, int tt) : x(xx), y(yy), t(tt) {}
};

inline void update_time(unsigned x, unsigned y, unsigned t) {
    if (x < MAX && y < MAX) {
        destroy[x][y] = std::min(destroy[x][y], t);
    }
}

void init() {
    int m;
    std::cin >> m;
    std::memset(destroy, -1, sizeof(destroy));
    while (m--) {
        unsigned x, y, t;
        std::cin >> x >> y >> t;
        update_time(x, y, t);
        for (int i = 0; i < 4; ++i) {
            update_time(x + dx[i], y + dy[i], t);
        }
    }
    std::memset(visited, 0, sizeof(visited));
}

void bfs() {
    if (destroy[0][0] == unsigned(-1)) {
        std::cout << "0\n";
        return;
    }
    std::queue<Node> q;
    q.push(Node(0, 0, 0));
    visited[0][0] = true;
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            unsigned x = cur.x + dx[i];
            unsigned y = cur.y + dy[i];
            unsigned t = cur.t + 1;
            if (x < MAX && y < MAX && !visited[x][y]) {
                visited[x][y] = true;
                if (destroy[x][y] == unsigned(-1)) {
                    std::cout << t << '\n';
                    return;
                } else if (destroy[x][y] > t) {
                    q.push(Node(x, y, t));
                }
            }
        }
    }
    std::cout << "-1\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    init();
    bfs();
    return 0;
}
