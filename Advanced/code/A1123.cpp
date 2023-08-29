#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val, height;
  TreeNode *left, *right;
} *root;
int n;

TreeNode* newNode(int x) {
  TreeNode *root = new TreeNode;
  root -> val = x;
  root -> height = 1;
  root -> left = root -> right = NULL;
  return root;
}

int getHeight(TreeNode *root) {
  if (!root)  return 0;
  else  return root -> height;
}

int getBalanceFactor(TreeNode *root) {
  return getHeight(root -> left) - getHeight(root -> right);
}

void updateHeight(TreeNode *root) {
  root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
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

bool flag = true;
void isCompleteTree(TreeNode *root, int x) {
  if (!root)  return;
  if (x > n)  flag = false;
  isCompleteTree(root -> left, 2 * x);
  isCompleteTree(root -> right, 2 * x + 1);
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
  int cur;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    insert(root, cur);
  }
  levelTraversal(root);
  isCompleteTree(root, 1);
  printf("\n%s", flag? "YES": "NO");
  return 0;
}