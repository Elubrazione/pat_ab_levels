#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> node, pre, preMirror, post, postMirror;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

void insert(TreeNode*& root, int x) {
  if (!root) {
    root = new TreeNode;
    root -> val = x;
    root -> left = root -> right = NULL;
    return;
  }
  if (x >= root -> val)  insert(root -> right, x);
  else  insert(root -> left, x);
}

void preOrderTraversal(TreeNode* root) {
  if (!root)  return;
  pre.push_back(root -> val);
  preOrderTraversal(root -> left);
  preOrderTraversal(root -> right);
}

void preMirrorTraversal(TreeNode* root) {
  if (!root)  return;
  preMirror.push_back(root -> val);
  preMirrorTraversal(root -> right);
  preMirrorTraversal(root -> left);
}

void postTraversal(TreeNode* root) {
  if (!root)  return;
  postTraversal(root -> left);
  postTraversal(root -> right);
  post.push_back(root -> val);
}

void postMirrorTraversal(TreeNode* root) {
  if (!root)  return;
  postMirrorTraversal(root -> right);
  postMirrorTraversal(root -> left);
  postMirror.push_back(root -> val);
}

int main() {
  cin >> n;
  TreeNode* root = NULL;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    node.push_back(k);
    insert(root, k);
  }
  preOrderTraversal(root);
  preMirrorTraversal(root);
  if (pre == node) {
    postTraversal(root);
    cout << "YES" << endl;
    for (int i = 0; i < post.size(); i++) {
      cout << post[i];
      if (i != post.size() - 1)
        cout << " ";
    }
  } else if (preMirror == node) {
    postMirrorTraversal(root);
    cout << "YES" << endl;
    for (int i = 0; i < postMirror.size(); i++) {
      cout << postMirror[i];
      if (i != postMirror.size() - 1)
        cout << " ";
    }
  } else {
    cout << "NO";
  }
  return 0;
}