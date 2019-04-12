#include <cstdio>

const int N = 5000 + 10;
bool is_forward[N];
int f[N];
int n;

int get_cnt(int k) {
    int sum = 0, cnt = 0;
    for (int i = 0; i <= n - k; ++i) {
        if ((sum + is_forward[i]) % 2) {
            f[i] = 0;
        } else {
            f[i] = 1;
        }
        sum += f[i];
        cnt += f[i];
        if (i - k + 1 >= 0) {
            sum -= f[i - k + 1];
        }
    }
    for (int i = n - k + 1; i < n; ++i) {
        if ((sum + is_forward[i]) % 2 == 0) return -1;
        if (i - k + 1 >= 0) {
            sum -= f[i - k + 1];
        }
    }
    return cnt;
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf("%c\n", &ch);
        is_forward[i] = (ch == 'F');
    }
    int min_k, min_cnt = 0x7f7f7f7f;
    for (int k = 1; k <= n; ++k) {
        int cnt = get_cnt(k);
        if (cnt >= 0 && cnt < min_cnt) {
            min_cnt = cnt;
            min_k = k;
        }
    }
    printf("%d %d\n", min_k, min_cnt);
}
