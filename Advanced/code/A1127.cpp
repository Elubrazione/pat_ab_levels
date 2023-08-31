#include <bits/stdc++.h>
using namespace std;
vector<int> in, post;

struct TreeNode {
  int val;
  TreeNode *left, *right;
};

TreeNode* insert(int inL, int inR, int postL, int postR) {
  if (inL > inR)  return NULL;
  TreeNode *root = new TreeNode;
  root -> val = post[postR];
  root -> left = root -> right = NULL;

  int k = inL;
  while (k <= inR && in[k] != post[postR])  k++;
  int numLeft = k - inL;
  root -> left = insert(inL, k - 1, postL, postL + numLeft - 1);
  root -> right = insert(k + 1, inR, postL + numLeft, postR - 1);
  return root;
}

int cnt = 1;
void levelTraversal(TreeNode *root, int n) {
  queue<TreeNode*> q;
  q.push(root);
  vector<int> vec;
  int ctrl = 1;
  while (!q.empty()) {
    int num = q.size();
    while (num--) {
      auto node =  q.front();
      q.pop();
      vec.push_back(node -> val);
      if (node -> left) q.push(node -> left);
      if (node -> right)  q.push(node -> right);
    }
    if (ctrl%2) reverse(vec.begin(), vec.end());
    for (auto p: vec) {
      cout << p;
      if (cnt != n) cout << " ";
      cnt++;
    }
    ctrl++;
    vec.clear();
  }
}

int main() {
  int n;
  cin >> n;
  in.resize(n);
  post.resize(n);
  for (int i = 0; i < n; i++) cin >> in[i];
  for (int i = 0; i < n; i++) cin >> post[i];
  TreeNode *root = insert(0, n - 1, 0, n - 1);
  levelTraversal(root, n);
  return 0;
}