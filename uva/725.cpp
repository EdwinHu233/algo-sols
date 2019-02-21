#include <bitset>
#include <iostream>
using namespace std;

bitset<10> use;
int b, n;  // a / b == n (or b * n == a)

inline bool match() {
  int a = b * n;
  auto mask = use;
  for (int i = 0; i < 5; ++i) {
    int r = a % 10;
    a /= 10;
    if (mask[r]) return false;
    mask[r] = true;
  }
  return a == 0;
}

inline void printResult() {
  int a = b * n;
  if (a < 10000) cout << '0';
  cout << a << " / ";
  if (b < 10000) cout << '0';
  cout << b << " = " << n << '\n';
}

inline bool backtrace(const int cur = 0) {
  if (cur == 5) {
    if (match()) {
      printResult();
      return true;
    } else {
      return false;
    }
  }
  bool flag = false;
  for (int i = 0; i < 10; ++i) {
    if (!use[i]) {
      use[i] = true;
      b = b * 10 + i;
      flag = flag || backtrace(cur + 1);
      b /= 10;
      use[i] = false;
    }
  }
  return flag;
}

int main() {
  while (cin >> n && n) {
    use.reset();
    if (!backtrace()) {
      cout << "There are no solutions for " << n << ".\n";
    }
    cout << '\n';
  }
  return 0;
}
