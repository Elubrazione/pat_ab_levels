#include <bits/stdc++.h>
using namespace std;
int n, idx = 0;
vector<int> node;
unordered_map<int, pair<int, int>> mp;

struct TreeNode {
  int order;
  int val;
  TreeNode* left;
  TreeNode* right;
};

void insert(TreeNode* &root) {
  if (mp[root->order].first >= 0) {
    TreeNode* l = new TreeNode;
    l -> order = mp[root->order].first;
    root -> left = l;
    insert(root -> left);
  } else {
    root -> left = NULL;
  }
  if (mp[root->order].second >= 0) {
    TreeNode* r = new TreeNode;
    r -> order = mp[root->order].second;
    root -> right = r;
    insert(root -> right);
  } else {
    root -> right = NULL;
  }
  return;
}

void inOrderTraversal(TreeNode* root) {
  if (!root)  return;
  inOrderTraversal(root -> left);
  root -> val = node[idx++];
  inOrderTraversal(root -> right);
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
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a,b;
    cin >> a >> b;
    mp[i] = make_pair(a, b);
  }
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    node.push_back(k);
  }
  sort(node.begin(), node.end());
  TreeNode* root = new TreeNode;
  root -> order = 0;
  insert(root);
  inOrderTraversal(root);
  levelTraversal(root);
  return 0;
}