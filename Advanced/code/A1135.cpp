#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
};
int pre, cur;

void create(TreeNode *&root, int x) {
  if (!root) {
    root = new TreeNode;
    root -> val = x;
    root -> left = root -> right = NULL;
    return;
  }
  if (abs(x) < abs(root -> val))  create(root -> left, x);
  else  create(root -> right, x);
}

void forLeaves(TreeNode *root, bool &flag) {
  if (!root || !flag) return;
  if (root -> val < 0) {
    if (root -> left) {
      if (root -> left -> val < 0) {
        flag = false;
        return;
      }
    }
    if (root -> right) {
      if (root -> right -> val < 0) {
        flag = false;
        return;
      }
    }
  }
  forLeaves(root -> left, flag);
  forLeaves(root -> right, flag);
}

void forBlackNum(TreeNode *root, bool &flag, int cur) {
  if (!flag)  return;
  if (!root) {
    if (pre == -1 || pre == cur) {
      pre = cur;
      return;
    } else {
      flag = false;
      return;
    }
  }
  int t = cur;
  if (root -> val > 0)  t++;
  forBlackNum(root -> left, flag, t);
  forBlackNum(root -> right, flag, t);
}

int main() {
  int k, num, temp;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> num;
    TreeNode *root = NULL;
    for (int j = 0; j < num; j++) {
      cin >> temp;
      create(root, temp);
    }
    pre = -1, cur = 0;
    bool flag = true;
    if (root -> val < 0)  flag = false;
    forLeaves(root, flag);
    forBlackNum(root, flag, 0);
    if (flag) cout << "Yes" << endl;
    else  cout << "No" << endl;
  }
  return 0;
}