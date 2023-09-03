#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
};
vector<int> in, pre, ans;

TreeNode* create(int preL, int preR, int inL, int inR) {
  if (preL > preR)  return NULL;
  TreeNode *root = new TreeNode;
  root -> val = pre[preL];
  root -> left = root -> right = NULL;
  int k = inL;
  while (k <= inR && in[k] != pre[preL])  k++;
  int leftNum = k - inL;
  root -> left = create(preL + 1, preL + leftNum, inL, k - 1);
  root -> right = create(preL + leftNum + 1, preR, k + 1, inR);
  return root;
}

void leftview(TreeNode *root) {
  if (!root)  return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int num = q.size();
    for (int i = 0; i < num; i++)  {
      TreeNode *cur = q.front();
      q.pop();
      if (!i) ans.push_back(cur -> val);
      if (cur -> left)  q.push(cur -> left);
      if (cur -> right) q.push(cur -> right);
    }
  }
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++)
    cout << " " << ans[i];
  return;
}

int main() {
  int n;
  cin >> n;
  in.resize(n);
  pre.resize(n);
  for (int i = 0; i < n; i++) cin >> in[i];
  for (int i = 0; i < n; i++) cin >> pre[i];
  TreeNode *root = create(0, n - 1, 0, n - 1);
  leftview(root);
  return 0;
}