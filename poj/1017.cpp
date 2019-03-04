#include <algorithm>
#include <iostream>
#include <vector>

int num[7];
int one_by_one, two_by_two;
int cnt;

bool init() {
    bool valid_case = false;
    for (int i = 1; i <= 6; ++i) {
        std::cin >> num[i];
        if (num[i] != 0) valid_case = true;
    }
    return valid_case;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (init()) {
        cnt = num[6] + num[5] + num[4];
        one_by_one = 11 * num[5];
        two_by_two = 5 * num[4];
        cnt += (num[3] + 3) / 4;
        switch (num[3] % 4) {
            case 3:
                two_by_two += 1;
                one_by_one += 5;
                break;
            case 2:
                two_by_two += 3;
                one_by_one += 6;
                break;
            case 1:
                two_by_two += 5;
                one_by_one += 7;
                break;
        }
        if (num[2] > two_by_two) {
            int remain = num[2] - two_by_two;
            cnt += (remain + 8) / 9;
            one_by_one += 4 * (9 - remain % 9);
        } else {
            one_by_one += (two_by_two - num[2]) * 4;
        }
        if (num[1] > one_by_one) {
            int remain = num[1] - one_by_one;
            cnt += (remain + 35) / 36;
        }
        std::cout << cnt << '\n';
    }
    return 0;
}
