#include <bits/stdc++.h>
using namespace std;
int n;
map<int, pair<int, int>> mp;
vector<bool> isRoot;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

void insert(TreeNode* &root) {
  if (mp[root->val].first < 0 && mp[root->val].second < 0)
    return;
  if (mp[root->val].first >= 0) {
    TreeNode* l = new TreeNode;
    l -> val = mp[root->val].first;
    root -> left = l;
    insert(root -> left);
  }
  else  root -> left = NULL;
  if (mp[root->val].second >= 0) {
    TreeNode* r = new TreeNode;
    r -> val = mp[root->val].second;
    root -> right = r;
    insert(root -> right);
  }
  else  root -> right = NULL;
  return;
}

void levelTraversal(TreeNode* root) {
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
  cout << endl;
  return;
}

int num = 0;
void inOrderTraversal(TreeNode* root) {
  if (!root)  return;
  inOrderTraversal(root -> left);
  cout << root -> val;
  num++;
  if (num < n)  cout << " ";
  inOrderTraversal(root -> right);
  return;
}

int main() {
  cin >> n;
  isRoot.resize(n, true);
  for (int i = 0; i < n; i++) {
    char s1, s2;
    cin >> s1 >> s2;
    int a, b;
    if (s1 == '-')  a = -1;
    else  a = s1 - '0';
    if (s2 == '-')  b = -1;
    else  b = s2 - '0';
    if (a != -1)  isRoot[a] = false;
    if (b != -1)  isRoot[b] = false;
    mp[i] = make_pair(b, a);
  }
  int i;
  for (i = 0; i < n; i++)
    if (isRoot[i])  break;
  TreeNode* root = new TreeNode;
  root -> val = i;
  insert(root);
  levelTraversal(root);
  inOrderTraversal(root);
  return 0;
}