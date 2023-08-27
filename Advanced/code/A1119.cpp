#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
};
bool flag = true;
vector<int> pre, post;

TreeNode* create(int preL, int preR, int postL, int postR) {
  TreeNode *root = new TreeNode;
  root -> val = pre[preL];
  root -> left = root -> right = NULL;
  if (preL == preR) return root;
  int k = preL + 1; // 最后找到的下标k属于右子树（若无歧义），其左边一定是左子树，数目为 k-(preL+1)
  while (k <= preR && pre[k] != post[postR-1])  k++;
  int len = k - preL - 1;
  if (len > 0) { // 不一样，无歧义
    root -> left = create(preL + 1, k - 1, postL, postL + len - 1);
  } else {  // 一样，有歧义，选择归到任意一边皆可（题目说输出任意一种，没有规定规则）
    flag = false;
  }
  root -> right = create(k, preR, postL + len, postR - 1);
  return root;
}

void inOrder(TreeNode *root) {
  if (!root)  return;
  inOrder(root -> left);
  if (flag) {
    cout << root -> val;
    flag = false;
  } else {
    cout << " " << root -> val;
  }
  inOrder(root -> right);
}

int main() {
  int n;
  cin >> n;
  pre.resize(n);
  post.resize(n);
  for (int i = 0; i < n; i++) cin >> pre[i];
  for (int i = 0; i < n; i++) cin >> post[i];
  TreeNode *root = create(0, n - 1, 0, n - 1);
  if (flag) cout << "Yes" << endl;
  else  cout << "No" << endl;
  flag = true;
  inOrder(root);
  cout << endl;
  return 0;
}