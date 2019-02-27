#include <iostream>
#include <set>

typedef std::set<std::string> Set;

Set distinct;

char map[5][5];
std::string str;

inline bool valid_pos(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

void init() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin >> map[i][j];
        }
    }
    str.resize(6);
}

void dfs(int x, int y, int n) {
    if (n == 6) {
        distinct.insert(str);
        return;
    }
    str[n] = map[x][y];
    static const int dx[] = {0, 0, -1, 1};
    static const int dy[] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (valid_pos(xx, yy)) dfs(xx, yy, n + 1);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    init();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            dfs(i, j, 0);
        }
    }
    std::cout << distinct.size() << '\n';
    return 0;
}
