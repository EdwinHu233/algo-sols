#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODE = 4000 * 100 + 5;
const int MAX_SIGMA = 26;
const int MAX_TEXT_LEN = 300000 + 5;
const int MOD = 20071027;

struct Trie {
  // At the begining, there is only one node (the root).
  // No 'child[u][i]' can be 0, since no node has the root as its child.
  // So we have the convention that
  // 'child[u][i] == 0' iff 'node u has no such child'
  int child[MAX_NODE][MAX_SIGMA];
  bool is_word[MAX_NODE];
  int size;

  void reset() {
    memset(child[0], 0, sizeof(child[0]));
    size = 1;
  }

  void insert(const string &s) {
    int u = 0;
    // For each char, go down a level in the tree.
    for (char c : s) {
      int i = c - 'a';
      if (child[u][i] == 0) {
        memset(child[size], 0, sizeof(child[size]));
        is_word[size] = 0;
        child[u][i] = size++;
      }
      u = child[u][i];
    }
    // Finally, we reach the leaf node (representing the word).
    is_word[u] = true;
  }

  void find_prefix(const string &s, const int start, vector<int> &result) {
    int u = 0;
    for (int i = start; i < s.size(); ++i) {
      int j = s[i] - 'a';
      if (child[u][j] == 0) return;
      u = child[u][j];
      // s[start..i] is a prefix of s[start..]
      if (is_word[u]) result.push_back(i);
    }
  }
};

// GLOBAL VARIABLES
Trie trie;
int cnt[MAX_TEXT_LEN];

void reset() {
  trie.reset();
  memset(cnt, 0, sizeof(cnt));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string text, word;
  int num_word, num_case = 0;
  while (cin >> text >> num_word) {
    reset();
    while (num_word--) {
      cin >> word;
      trie.insert(word);
    }
    vector<int> pos;
    cnt[text.size()] = 1;
    for (int i = text.size() - 1; i >= 0; --i) {
      pos.clear();
      trie.find_prefix(text, i, pos);
      for (auto j : pos) {
        cnt[i] = (cnt[i] + cnt[j + 1]) % MOD;
      }
    }
    cout << "Case " << ++num_case << ": " << cnt[0] << '\n';
  }
  return 0;
}
