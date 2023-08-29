#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
};
bool flag = true;
vector<int> pre, post, in;

TreeNode* create(int preL, int preR, int postL, int postR) {
  TreeNode *root = new TreeNode;
  root -> val = pre[preL];
  root -> left = root -> right = NULL;
  if (preL == preR) {
    in.push_back(pre[preL]);
    return root;
  }
  int k = preL + 1;
  while (k <= preR && pre[k] != post[postR-1])  k++;
  int len = k - preL - 1;
  if (len > 0)
    root -> left = create(preL + 1, k - 1, postL, postL + len - 1);
  else  flag = false;
  in.push_back(post[postR]);
  root -> right = create(k, preR, postL + len, postR - 1);
  return root;
}

int main() {
  int n;
  cin >> n;
  pre.resize(n);
  post.resize(n);
  for (int i = 0; i < n; i++) cin >> pre[i];
  for (int i = 0; i < n; i++) cin >> post[i];
  TreeNode *root = create(0, n - 1, 0, n - 1);
  printf("%s\n%d", flag == true ? "Yes" : "No", in[0]);
  for (int i = 1; i < in.size(); i++)
    printf(" %d", in[i]);
  cout << endl;
  return 0;
}