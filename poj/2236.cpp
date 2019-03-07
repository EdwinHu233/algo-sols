#include <algorithm>
#include <cstdio>

const int N = 1010;
struct Computer {
    int x, y;
    bool good;
};

int n, d;
Computer cs[N];
int id[N];

bool near(const Computer &a, const Computer &b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy <= d * d;
}

int find(int x) { return (id[x] == x) ? x : (id[x] = find(id[x])); }
void unite(int x, int y) { id[find(x)] = find(y); }

void init() {
    scanf("%d%d\n", &n, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d\n", &cs[i].x, &cs[i].y);
        cs[i].good = false;
        id[i] = i;
    }
}

bool test() {
    char buffer[20];
    if (!fgets(buffer, sizeof(buffer), stdin)) return false;
    if (buffer[0] == 'O') {
        int p;
        sscanf(buffer + 1, "%d", &p);
        if (!cs[p].good) {
            cs[p].good = true;
            for (int i = 1; i <= n; ++i) {
                if (cs[i].good && near(cs[i], cs[p])) unite(i, p);
            }
        }
    } else {
        int p, q;
        sscanf(buffer + 1, "%d%d", &p, &q);
        if (cs[p].good && cs[q].good && find(p) == find(q)) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }
    return true;
}

int main() {
    init();
    while (test()) continue;
    return 0;
}
