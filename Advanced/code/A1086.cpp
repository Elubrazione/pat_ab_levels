#include <bits/stdc++.h>
using namespace std;
int n, num = 0;
vector<int> preOrder, inOrder;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* create(int preL, int preR, int inL, int inR) {
  if (preL > preR)  return NULL;
  TreeNode* root = new TreeNode;
  root -> val = preOrder[preL];
  int k;
  for (k = inL; k <= inR; k++)
    if (inOrder[k] == preOrder[preL])
      break;
  int numLeft = k - inL;
  root -> left = create(preL + 1, preL + numLeft, inL, k - 1);
  root -> right = create(preL + numLeft + 1, preR, k + 1, inR);
  return root;
}

void postTraversal(TreeNode* root) {
  if (!root)  return;
  postTraversal(root -> left);
  postTraversal(root -> right);
  cout << root ->val;
  num++;
  if (num < n)  cout << " ";
  return;
}

int main() {
  stack<int> stk;
  cin >> n;
  for (int i = 0; i < n * 2; i++) {
    string s;
    int temp;
    cin >> s;
    if (s == "Push") {
      cin >> temp;
      preOrder.push_back(temp);
      stk.push(temp);
    } else {
      temp = stk.top();
      stk.pop();
      inOrder.push_back(temp);
    }
  }
  TreeNode* root = create(0, n-1, 0, n-1);
  postTraversal(root);
  return 0;
}