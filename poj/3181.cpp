#include <algorithm>
#include <iostream>

typedef unsigned long long ULL;
const int N_MAX = 1000 + 5;

struct Number {
    // LIMIT * 2 < UINT64_MAX (to make '+=' easier)
    // LIMIT % 10 == 0 (to make '<<' easier)
    static const ULL LIMIT = 1000000000000000000;

    ULL high, low;
    Number() : high(0), low(0) {}
    void operator+=(const Number &rhs) {
        low += rhs.low;
        ULL carry = low / LIMIT;
        low %= LIMIT;
        high += rhs.high + carry;
    }
};

std::ostream &operator<<(std::ostream &os, const Number &n) {
    if (n.high != 0) {
        os << n.high;
    }
    os << n.low;
    return os;
}

Number dp[N_MAX];
int N, K;

int main() {
    std::cin >> N >> K;
    dp[0].low = 1;
    for (int i = 1; i <= K; ++i) {
        for (int j = i; j <= N; ++j) {
            dp[j] += dp[j - i];
        }
    }
    std::cout << dp[N] << '\n';
    return 0;
}

