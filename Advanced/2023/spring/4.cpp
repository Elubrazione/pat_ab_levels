#include <bits/stdc++.h>
using namespace std;
vector<int> post, in;
struct TreeNode {
  int val, idx;
  TreeNode *left, *right;
};
vector<int> lpath, rpath;

TreeNode* create(int inL, int inR, int postL, int postR) {
  if (postL > postR)  return NULL;
  TreeNode *root = new TreeNode;
  root -> idx = -1;
  root -> val = post[postR];
  root -> left = root -> right = NULL;
  int k = inL;
  while (k <= inR && in[k] != post[postR])  k++;
  int numLeft = k - inL;
  root -> left = create(inL, k - 1, postL, postL + numLeft - 1);
  root -> right = create(k + 1, inR, postL + numLeft, postR - 1);
  return root;
}

void isSymmetric(vector<vector<pair<int, int>>> &ans) {
  int num = 1;
  bool flag = true;
  for (int i = 1; i < ans.size(); i++) {
    num *= 2;
    int s = ans[i].size();
    if (ans[i].size() % 2 != 0) flag = false;
    for (int j = 0; j < s / 2; j++) {
      if (ans[i][j].second - num != num * 2 - 1 - ans[i][s-1-j].second) flag = false;
    }
  }
  if (flag) cout << "Yes" << endl;
  else  cout << "No" << endl;
}

void levelTraverse(TreeNode *root) {
  int cnt = 1;
  queue<TreeNode*> q;
  q.push(root);
  vector<pair<int, int>> temp;
  vector<vector<pair<int, int>>> ans;
  while (!q.empty()) {
    int num = q.size();
    temp.clear();
    for (int i = 0; i < num; i++) {
      TreeNode *cur = q.front();
      q.pop();
      if (cur -> left)  q.push(cur -> left);
      if (cur -> right) q.push(cur -> right);
      if ((cur->left == NULL && cur->right == NULL) || cur->idx == cnt || cur->idx == cnt*2-1) {
        // cout << cur -> idx << " ";
        temp.push_back({cur -> val, cur -> idx});
      }
    }
    cout << endl;
    ans.push_back(temp);
    cnt *= 2;
  }
  isSymmetric(ans);
}

void dfs(TreeNode *root, int idx) {
  if (!root)  return;
  root -> idx = idx;
  dfs(root -> left, 2 * idx);
  dfs(root -> right, 2 * idx + 1);
}

int main() {
  int n;
  cin >> n;
  post.resize(n);
  in.resize(n);
  for (int i = 0; i < n; i++) cin >> in[i];
  for (int i = 0; i < n; i++) cin >> post[i];
  TreeNode *root = create(0, n - 1, 0, n - 1);
  dfs(root, 1);
  levelTraverse(root);
  return 0;
}