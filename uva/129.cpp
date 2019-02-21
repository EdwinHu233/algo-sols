#include <iostream>

int buffer[80];
int L, n, cnt, totalLen;

bool validate(const int cur) {
  for (int len = 1; len * 2 <= cur + 1; ++len) {
    int base1 = cur - len + 1, base2 = cur - 2 * len + 1;
    int j = 0;
    while (j < len && buffer[base1 + j] == buffer[base2 + j]) {
      ++j;
    }
    if (j == len) return false;
  }
  return true;
}

bool dfs(const int cur) {
  for (int i = 0; i < L; ++i) {
    buffer[cur] = i;
    if (validate(cur)) {
      ++cnt;
      if (cnt == n) {
        totalLen = cur + 1;
        return true;
      } else if (dfs(cur + 1)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  while (std::cin >> n >> L && n && L) {
    cnt = 0;
    dfs(0);
    for (int i = 1; i <= totalLen; ++i) {
      std::cout << char(buffer[i - 1] + 'A');
      if (i != totalLen) {
        if (i == 16 * 4)
          std::cout << '\n';
        else if (i % 4 == 0)
          std::cout << ' ';
      }
    }
    std::cout << '\n' << totalLen << '\n';
  }
  return 0;
}
