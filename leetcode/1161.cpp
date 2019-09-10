#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int best_sum = numeric_limits<int>::min(), best_level = 0;
    int current_sum = 0, current_level = 0;
    while (!q.empty()) {
      current_level++;
      current_sum = 0;
      size_t n = q.size();
      while (n--) {
        auto p = q.front();
        q.pop();
        current_sum += p->val;
        if (p->left) {
          q.push(p->left);
        }
        if (p->right) {
          q.push(p->right);
        }
      }
      if (current_sum > best_sum) {
        best_sum = current_sum;
        best_level = current_level;
      }
    }
    return best_level;
  }
};
