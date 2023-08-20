/**
 * 给定一棵二叉树的后序遍历和中序遍历，
 * 请你输出其层序遍历的序列。
 * 这里假设键值都是互不相等的正整数
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> postOrder, inOrder;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* create(int postL, int postR, int inL, int inR) {
  if (postL > postR)
    return NULL;
  TreeNode* root = new TreeNode;
  root -> val = postOrder[postR];
  int k;
  for (k = inL; k <= inR; k++)
    if (inOrder[k] == postOrder[postR])
      break;
  int numberLeft = k - inL;
  root -> left = create(postL, postL + numberLeft - 1, inL, k - 1);
  root -> right = create(postL + numberLeft, postR - 1, k + 1, inR);
  return root;
}

void levelTraversal(TreeNode* root, int n) {
  if (!root)  return;
  queue<TreeNode*> q;
  q.push(root);
  int num = 0;
  while(!q.empty()) {
    TreeNode* cur = q.front();
    q.pop();
    cout << cur -> val;
    num++;
    if (num < n)  cout << " ";
    if (cur -> left)  q.push(cur -> left);
    if (cur -> right)  q.push(cur -> right);
  }
  return;
}

int main() {
  int n;
  cin >> n;
  postOrder.resize(n);
  inOrder.resize(n);
  for (int i = 0; i < n; i++)  cin >> postOrder[i];
  for (int i = 0; i < n; i++)  cin >> inOrder[i];
  TreeNode* root = create(0, n-1, 0, n-1);
  levelTraversal(root, n);
  return 0;
}