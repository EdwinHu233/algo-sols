#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Node {
  string s;
  int lc, rc;  // left and right children, represented by id
  int order;
};

bool operator<(const Node &a, const Node &b) {
  if (a.s != b.s) return a.s < b.s;
  if (a.lc != b.lc) return a.lc < b.lc;
  return a.rc < b.rc;
}

vector<Node> nodeCache;
map<Node, int> idCache;

int getID(const Node &a) {
  if (idCache.find(a) == idCache.end()) {
    nodeCache.push_back(a);
    idCache[a] = nodeCache.size() - 1;
  }
  return idCache[a];
}

int buildNode(const string &exp, int &i) {
  while (!isalpha(exp[i])) ++i;
  Node a;
  while (isalpha(exp[i])) {
    a.s.push_back(exp[i]);
    ++i;
  }
  if (exp[i] == '(') {
    a.lc = buildNode(exp, i);
    a.rc = buildNode(exp, i);
  } else {
    a.lc = a.rc = -1;
  }
  a.order = 0;
  return getID(a);
}

void printSubTree(int id, int &cnt) {
  Node &cur = nodeCache[id];
  if (cur.order != 0) {
    cout << cur.order;
  } else {
    cur.order = ++cnt;
    cout << cur.s;
    if (cur.lc >= 0) {
      cout << '(';
      printSubTree(cur.lc, cnt);
      cout << ',';
      printSubTree(cur.rc, cnt);
      cout << ')';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  string exp;
  cin >> T;
  getline(cin, exp);
  while (T--) {
    getline(cin, exp);
    nodeCache.clear();
    idCache.clear();
    int i = 0, cnt = 0;
    int rootID = buildNode(exp, i);
    printSubTree(rootID, cnt);
    cout << '\n';
  }
  return 0;
}
