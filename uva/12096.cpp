#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define INS(x) inserter(x, x.begin())
#define ALL(x) x.begin(), x.end()

using Set = set<int>;
map<Set, int> idCache;
vector<Set> setCache;

int getID(const Set &s) {
  if (idCache.find(s) == idCache.end()) {
    setCache.push_back(s);
    idCache[s] = setCache.size() - 1;
  }
  return idCache[s];
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, num;
  string opWord;
  cin >> T;
  while (T--) {
    cin >> num;
    stack<int> stk;
    while (num--) {
      cin >> opWord;
      if (opWord[0] == 'P') {
        stk.push(getID(Set()));
      } else if (opWord[0] == 'D') {
        stk.push(stk.top());
      } else {
        Set s1 = setCache[stk.top()];
        stk.pop();
        Set s2 = setCache[stk.top()];
        stk.pop();
        Set result;
        if (opWord[0] == 'U') {
          set_union(ALL(s1), ALL(s2), INS(result));
        } else if (opWord[0] == 'I') {
          set_intersection(ALL(s1), ALL(s2), INS(result));
        } else {
          s2.insert(getID(s1));
          result = s2;
        }
        stk.push(getID(result));
      }
      cout << setCache[stk.top()].size() << '\n';
    }
    cout << "***\n";
  }
  return 0;
}
