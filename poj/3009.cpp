#include <cstring>
#include <iostream>
using namespace std;

typedef std::pair<int, int> Pos;
const int H_MAX = 20, W_MAX = 20;
const int STEP = 10;

int H, W;
bool block[H_MAX][W_MAX];
Pos cur, dst;
int min_step;
bool success;

bool init() {
    std::cin >> W >> H;
    if (W == 0) return false;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            int tmp;
            std::cin >> tmp;
            block[h][w] = (tmp == 1);
            if (tmp == 2) {
                cur = Pos(h, w);
            } else if (tmp == 3) {
                dst = Pos(h, w);
            }
        }
    }
    min_step = STEP;
    success = false;
    return true;
}

inline bool is_valid(int h, int w) {
    return h >= 0 && h < H && w >= 0 && w < W;
}

void dfs(const int step) {
    if (step >= min_step) return;
    static const int dh[] = {0, 0, -1, 1};
    static const int dw[] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; ++i) {
        int h = cur.first + dh[i];
        int w = cur.second + dw[i];
        if (!is_valid(h, w) || block[h][w]) continue;
        while (true) {
            if (Pos(h, w) == dst) {
                min_step = std::min(min_step, step + 1);
                success = true;
                return;
            } else if (!is_valid(h, w)) {
                break;
            } else if (block[h][w]) {
                Pos old_cur = cur;
                cur = Pos(h + dh[i ^ 1], w + dw[i ^ 1]);
                block[h][w] = false;
                dfs(step + 1);
                block[h][w] = true;
                cur = old_cur;
                break;
            } else {
                h += dh[i];
                w += dw[i];
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (init()) {
        dfs(0);
        std::cout << (success ? min_step : -1) << std::endl;
    }
    return 0;
}
