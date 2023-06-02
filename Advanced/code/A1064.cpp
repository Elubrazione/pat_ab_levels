/*
* 完全二叉树：
* 除了最下面一层之外，其余层的结点个数都达到了当层能达到的最大结点数，
* 且最下面一层只从左至右连续存在若干结点，而这些结点右边的结点全部不存在。
*/

#include <bits/stdc++.h>
using namespace std;
int n, idx = 0;
vector<int> node, cbt;

// 二叉排序树的中序遍历是递增的，按顺序赋值给cbt
void inOrderTraversal(int x) {
  if (x > n)  return;
  inOrderTraversal(x * 2);  // 左子树
  cbt[x] = node[idx++];
  inOrderTraversal(x * 2 + 1);  // 右子树
}

int main() {
  cin >> n;
  cbt.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    node.push_back(k);
  }
  sort(node.begin(), node.end());
  inOrderTraversal(1);  // 编号从1开始，如果从0开始则左子树是(x*2+1)，右子树是(x*2+2)
  // cbt数组按顺序输出就是其层序遍历
  for (int i = 1; i <= n; i++) {
    cout << cbt[i];
    if (i < n)  cout << " ";
  }
  return 0;
}