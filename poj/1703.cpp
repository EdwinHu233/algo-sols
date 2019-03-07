#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100000 + 10;
struct UF {
    int id[N];
    void reset(int n) {
        for (int i = 0; i <= n; ++i) id[i] = i;
    }
    int find(int x) { return (x == id[x]) ? x : (id[x] = find(id[x])); }
    void unite(int x, int y) { id[find(x)] = find(y); }
};

int gid[N];  // -1: invalid
int gn;
UF uf;
int n, m;

void d(int x, int y) {
    int &gx = gid[x], &gy = gid[y];
    if (gx < 0) {
        if (gy < 0) {
            gx = gn++;
            gy = gn++;
        } else {
            gx = gy ^ 1;
        }
    } else {
        if (gy < 0) {
            gy = gx ^ 1;
        } else {
            uf.unite(gx, gy ^ 1);
            uf.unite(gx ^ 1, gy);
        }
    }
}

void a(int x, int y) {
    if (gid[x] < 0 || gid[y] < 0) {
        printf("Not sure yet.\n");
    } else {
        int rx = uf.find(gid[x]);
        int ry = uf.find(gid[y]);
        if (rx == ry) {
            printf("In the same gang.\n");
        } else if (rx == (ry ^ 1)) {
            printf("In different gangs.\n");
        } else {
            printf("Not sure yet.\n");
        }
    }
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d%d\n", &n, &m);
        uf.reset(n);
        memset(gid, -1, sizeof(gid));
        gn = 0;
        while (m--) {
            char c;
            int x, y;
            scanf("%c%d%d\n", &c, &x, &y);
            if (c == 'A') {
                a(x, y);
            } else {
                d(x, y);
            }
        }
    }
    return 0;
}
