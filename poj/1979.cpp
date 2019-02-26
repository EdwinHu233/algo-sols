#include <cstring>
#include <iostream>
#include <queue>

typedef std::pair<int, int> Pos;

const int H_MAX = 20, W_MAX = 20;
int H, W;
int src_h, src_w;
bool black[H_MAX][W_MAX];
bool visit[H_MAX][W_MAX];

bool init() {
    std::cin >> W >> H;
    if (W == 0) return false;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            char c;
            std::cin >> c;
            if (c == '@') {
                src_h = h, src_w = w;
                black[h][w] = true;
            } else {
                black[h][w] = (c == '.');
            }
        }
    }
    return true;
}

int bfs() {
    std::memset(visit, 0, sizeof(visit));
    visit[src_h][src_w] = true;
    std::queue<Pos> q;
    q.push(std::make_pair(src_h, src_w));
    int cnt = 1;
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();
        static const int dh[] = {0, -1, 0, 1};
        static const int dw[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; ++i) {
            int h = cur.first + dh[i];
            int w = cur.second + dw[i];
            if (h >= 0 && h < H && w >= 0 && w < W && black[h][w] &&
                !visit[h][w]) {
                visit[h][w] = true;
                ++cnt;
                q.push(std::make_pair(h, w));
            }
        }
    }
    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (init()) std::cout << bfs() << '\n';
    return 0;
}
