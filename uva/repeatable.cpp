#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void print_permutation(const vector<int> &target, vector<int> &work,
                       int cur = 0) {
  int n = target.size();
  if (cur == n) {
    for (int i = 0; i < n; ++i) cout << work[i] << ',';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0 && target[i - 1] == target[i]) continue;
    int cnt_tgt = 0, cnt_work = 0;
    for (int j = 0; j < n; ++j) {
      if (target[j] == target[i]) cnt_tgt++;
    }
    for (int j = 0; j < cur; ++j) {
      if (work[j] == target[i]) cnt_work++;
    }
    if (cnt_work < cnt_tgt) {
      work[cur] = target[i];
      print_permutation(target, work, cur + 1);
    }
  }
}

int main() {
  srand(time(nullptr));
  int n;
  cin >> n;
  vector<int> target(n), work(n);
  for (int i = 0; i < n; ++i) {
    target[i] = rand() % n;
  }
  sort(target.begin(), target.end());
  cout << "Target: ";
  for (int i = 0; i < n; ++i) cout << target[i] << ',';
  cout << "\nPermutations:\n";
  print_permutation(target, work);
  return 0;
}
