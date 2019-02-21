#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void print_subset(vector<int> &v, unsigned bits) {
  for (unsigned i = 0; i < v.size(); ++i) {
    if (bits & (1 << i)) cout << v[i] << ',';
  }
  cout << '\n';
}

int main() {
  srand(time(nullptr));
  int n;
  cin >> n;
  vector<int> v(n);
  cout << "Full set: ";
  for (int &i : v) {
    i = rand() % n;
    cout << i << ',';
  }
  cout << "\nSubsets:\n";
  for (unsigned bits = 0; bits < (1 << n); ++bits) {
    print_subset(v, bits);
  }
  return 0;
}
