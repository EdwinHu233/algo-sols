#include <algorithm>
#include <iostream>

int weight[11][10] = {
    {0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 2, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 3, 3, 1, 0, 0, 0, 0, 0, 0},
    {1, 4, 6, 4, 1, 0, 0, 0, 0, 0},
    {1, 5, 10, 10, 5, 1, 0, 0, 0, 0},
    {1, 6, 15, 20, 15, 6, 1, 0, 0, 0},
    {1, 7, 21, 35, 35, 21, 7, 1, 0, 0},
    {1, 8, 28, 56, 70, 56, 28, 8, 1, 0},
    {1, 9, 36, 84, 126, 126, 84, 36, 9, 1},
};

int nums[10];
int N, sum;

bool test(int cnt, int cur) {
    if (cnt == N) {
        do {
            int tmp = 0;
            for (int i = 0; i < N; ++i) {
                tmp += nums[i] * weight[N][i];
            }
            if (tmp == sum) return true;
        } while (std::next_permutation(nums, nums + N));
        return false;
    } else if (cur > 10) {
        return false;
    } else {
        nums[cnt] = cur;
        return test(cnt + 1, cur + 1) || test(cnt, cur + 1);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> N >> sum;
    test(0, 1);
    for (int i = 0; i < N; ++i) {
        if (i) std::cout << ' ';
        std::cout << nums[i];
    }
    std::cout << '\n';
    return 0;
}
