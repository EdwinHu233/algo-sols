#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 300 + 5;
const int INF = 0x7f7f7f7f / 10;
int G[N][N];
int buffer[N];
int n, m;

void init() {
    scanf("%d%d", &n, &m);
    std::fill_n((int*)G, N * N, INF);
    for (int i = 1; i <= n; ++i) {
        G[i][i] = 0;
    }
    while (m--) {
        int mi;
        scanf("%d", &mi);
        for (int i = 0; i < mi; ++i) {
            scanf("%d", buffer + i);
        }
        for (int i = 0; i < mi; ++i) {
            for (int j = i + 1; j < mi; ++j) {
                int x = buffer[i], y = buffer[j];
                G[x][y] = G[y][x] = 1;
            }
        }
    }
}

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main() {
    init();
    floyd();
    int min_dist = INF;
    for (int i = 1; i <= n; ++i) {
        int dist = 0;
        for (int j = 1; j <= n; ++j) {
            dist += G[i][j];
        }
        min_dist = std::min(min_dist, dist);
    }
    double ans = double(min_dist * 100) / (n - 1);
    printf("%d\n", int(ans));
    return 0;
}
