#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10000 + 10;
bool is_prime[N];
vector<int> ps;

void init() {
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            ps.push_back(i);
            for (int j = i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int solve(const int x) {
    int a = 0, b = 0;
    int ans = 0, sum = 0;
    int n = ps.size();
    while (a < n && b <= n) {
        if (sum < x && b < n) {
            sum += ps[b++];
        } else {
            if (sum == x) ++ans;
            sum -= ps[a++];
        }
    }
    return ans;
}

int main() {
    init();
    int x;
    while (true) {
        scanf("%d", &x);
        if (x == 0) break;
        printf("%d\n", solve(x));
    }
}
