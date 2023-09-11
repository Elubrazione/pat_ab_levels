#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
};
vector<int> pre, in, ans(3);

TreeNode* insert(int preL, int preR, int inL, int inR) {
  if (preL > preR)  return NULL;
  TreeNode *root = new TreeNode;
  root -> val = pre[preL];
  root -> left = root -> right = NULL;
  int k = inL;
  while (k != inR && in[k] != pre[preL])  k++;
  int numLeft = k - inL;
  root -> left = insert(preL + 1, preL + numLeft, inL, k - 1);
  root -> right = insert(preL + numLeft + 1, preR, k + 1, inR);
  return root;
}

void dfs(TreeNode *root) {
  if (!root)  return;
  if (root -> left && root -> right)  ans[2]++;
  else if (root -> left || root -> right) ans[1]++;
  else  ans[0]++;
  dfs(root -> left);
  dfs(root -> right);
}

int main() {
  int n;
  cin >> n;
  pre.resize(n);
  in.resize(n);
  for (int i = 0; i < n; i++) cin >> in[i];
  for (int i = 0; i < n; i++) cin >> pre[i];
  TreeNode *root = insert(0, n - 1, 0, n - 1);
  dfs(root);
  printf("%d * %d / %d = %d", ans[1], ans[2], ans[0], ans[1]*ans[2]/ans[0]);
  return 0;
}