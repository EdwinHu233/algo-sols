#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int tmp, leftmost;
  uint64_t labol, num;
  while (scanf("%lu", &num) && num) {
    labol = leftmost = tmp = 0;
    while (num--) {
      scanf("%d", &tmp);
      leftmost += tmp;
      labol += abs(leftmost);
    }
    printf("%lu\n", labol);
  }
  return 0;
}
