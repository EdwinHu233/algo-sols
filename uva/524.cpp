#include <cstring>
#include <iostream>

bool prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
                0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0};

int nums[16];
bool visited[16];
int n;

void dfs(int cur) {
  if (cur == n) {
    if (prime[nums[n - 1] + nums[0]]) {
      std::cout << "1";
      for (int i = 1; i < n; ++i) {
        std::cout << ' ' << nums[i];
      }
      std::cout << '\n';
    }
  } else {
    for (int i = 2; i <= n; ++i) {
      if (!visited[i] && prime[i + nums[cur - 1]]) {
        visited[i] = true;
        nums[cur] = i;
        dfs(cur + 1);
        visited[i] = false;
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int numCase = 0;
  while (std::cin >> n) {
    if (numCase != 0) std::cout << '\n';
    std::cout << "Case " << (++numCase) << ":\n";
    memset(visited, 0, sizeof(visited));
    visited[1] = true;
    nums[0] = 1;
    dfs(1);
  }
  return 0;
}
