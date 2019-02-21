#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  srand(time(nullptr));
  vector<int> v(n);
  for (auto &i : v) i = rand() % (n * 2);
  sort(v.begin(), v.end());
  while (true) {
    for (int i : v) cout << i << ',';
    cout << '\n';
    if (!next_permutation(v.begin(), v.end())) break;
  }
  return 0;
}
