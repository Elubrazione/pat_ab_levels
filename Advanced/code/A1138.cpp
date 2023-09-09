#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in;
bool flag = false;
struct TreeNode {
  int val;
  TreeNode *left, *right;
};

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

void postTraversal(TreeNode *root) {
  if (!root || flag)  return;
  postTraversal(root -> left);
  postTraversal(root -> right);
  if (!flag) {
    cout << root -> val;
    flag = true;
  } else {
    return;
  }
}

int main() {
  int n;
  cin >> n;
  pre.resize(n);
  in.resize(n);
  for (int i = 0; i < n; i++)  cin >> pre[i];
  for (int i = 0; i < n; i++)  cin >> in[i];
  TreeNode *root = create(0, n - 1, 0, n - 1);
  postTraversal(root);
  return 0;
}