#include <cctype>
#include <cstdio>
using namespace std;

const int N = 2020;
char src[N];

// src[p..q) is remained
int p, q;
char take() {
    int i = p, j = q - 1;
    while (i < j && src[i] == src[j]) {
        ++i, --j;
    }
    if (src[i] < src[j]) {
        return src[p++];
    } else {
        return src[--q];
    }
}

int main() {
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        char c = getchar();
        while (!isalpha(c)) c = getchar();
        src[i] = c;
    }
    p = 0, q = cnt;
    for (int i = 0; i < cnt; ++i) {
        if (i % 80 == 0 && i != 0) putchar('\n');
        putchar(take());
    }
    return 0;
}
