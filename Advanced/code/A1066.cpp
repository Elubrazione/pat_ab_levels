#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  int height;
  TreeNode* left;
  TreeNode* right;
} *root;

TreeNode* newNode(int v) {
  TreeNode* root = new TreeNode;
  root -> val = v;
  root -> height = 1;
  root -> left = root -> right = NULL;
  return root;
}

int getHeight(TreeNode* root) {
  if (!root)  return 0;
  return root -> height;
}

int getBalanceFactor(TreeNode* root) {
  return getHeight(root -> left) - getHeight(root -> right);
}

void updateHeight(TreeNode* root) {
  root -> height = max(getHeight(root ->left), getHeight(root -> right)) + 1;
}

void r_rotation(TreeNode* &root) {
  TreeNode* temp = root -> left;
  root -> left = temp -> right;
  temp -> right = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
  return;
}

void l_rotation(TreeNode* &root) {
  TreeNode* temp = root -> right;
  root -> right = temp -> left;
  temp -> left = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
  return;
}

void insert(TreeNode* &root, int k) {
  if (root == NULL) {
    root = newNode(k);
    return;
  }
  if (k < root -> val) {
    insert(root -> left, k);
    updateHeight(root);
    if (getBalanceFactor(root) == 2) {
      if (getBalanceFactor(root -> left) == 1)  // LL
        r_rotation(root);
      else if (getBalanceFactor(root -> left) == -1) {  // LR
        l_rotation(root -> left);
        r_rotation(root);
      }
    }
  } else {
    insert(root -> right, k);
    updateHeight(root);
    if (getBalanceFactor(root) == -2) {
      if (getBalanceFactor(root -> right) == -1)  // RR
        l_rotation(root);
      else if (getBalanceFactor(root -> right) == 1) {  // RL
        r_rotation(root -> right);
        l_rotation(root);
      }
    }
  }
  return;
}

int main() {
  int n, k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    insert(root, k);
  }
  cout << root -> val;
  return 0;
}