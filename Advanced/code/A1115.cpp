#include <bits/stdc++.h>
using namespace std;
vector<bool> vis;
int maxDepth, n1, n2;

struct TreeNode {
  int id;
  int val;
  TreeNode* left;
  TreeNode* right;
};
int n;

void insert(TreeNode* & root, int x, int depth, int _id) {
  if (!root) {
    root = new TreeNode;
    root -> id = _id;
    root -> val = x;
    root -> left = root -> right = NULL;
    maxDepth = max(maxDepth, depth);
    return;
  }
  if (x > root -> val) insert(root -> right, x, depth + 1, _id);
  else  insert(root -> left, x, depth + 1, _id);
}

void dfs(TreeNode* root, int depth) {
  if (!root)  return;
  if (vis[root->id] == false) {
    if (depth == maxDepth) {
      n1++;
      vis[root->id] = true;
    } else if (depth == maxDepth - 1) {
      n2++;
      vis[root->id] = true;
    }
  }
  dfs(root -> left, depth + 1);
  dfs(root -> right, depth + 1);
}

int main() {
  cin >> n;
  vis.resize(n, false);
  TreeNode* root = NULL;
  int k;
  for (int i = 0; i < n; i++) {
    cin >> k;
    insert(root, k, 1, i);
  }
  dfs(root, 1);
  printf("%d + %d = %d", n1, n2, n1 + n2);
  return 0;
}