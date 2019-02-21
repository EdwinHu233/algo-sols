#include <iostream>

const int MAX = 105;

bool has_oil[MAX][MAX];
int ids[MAX][MAX];

int num_row, num_col;

bool should_visit(int row, int col) {
    return row >= 0 && row < num_row && col >= 0 && col < num_col &&
           has_oil[row][col] && ids[row][col] == 0;
}

void init_graph() {
    char c;
    for (int row = 0; row < num_row; row++) {
        for (int col = 0; col < num_col; ++col) {
            std::cin >> c;
            has_oil[row][col] = (c == '@');
            ids[row][col] = 0;
        }
    }
}

void dfs(int row, int col, int id) {
    if (!should_visit(row, col)) return;
    ids[row][col] = id;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            dfs(row + i, col + j, id);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (std::cin >> num_row >> num_col && num_row) {
        init_graph();
        int cnt = 0;
        for (int i = 0; i < num_row; ++i) {
            for (int j = 0; j < num_col; ++j) {
                if (should_visit(i, j)) {
                    ++cnt;
                    dfs(i, j, cnt);
                }
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}
