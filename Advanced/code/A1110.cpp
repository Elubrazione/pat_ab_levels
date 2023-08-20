// 注意N的上限是20，所以输入要设成string而不能是char
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int left, right;
};
vector<Node> node;
vector<bool> isRoot;
int ans, maxn = -1;

void dfs(int root, int idx) {
  if (idx > maxn) {
    // maxn用来记录当前位置下标，等会用于比较是否大于结点个数来判断是否是完全二叉树
    // ans用来记录最后一个最后一个结点的值
    // idx > maxn的条件是用来防止覆盖的
    maxn = idx;
    ans = root;
  }
  if (node[root].left != -1)
    dfs(node[root].left, 2 * idx);
  if (node[root].right != -1)
    dfs(node[root].right, 2 * idx + 1);
  return;
}

int main () {
  int n;
  cin >> n;
  node.resize(n);
  isRoot.resize(n, true);
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    if (a == "-")  node[i].left = -1;
    else {
      node[i].left = stoi(a);
      isRoot[stoi(a)] = false;
    }
    if (b == "-")  node[i].right = -1;
    else {
      node[i].right = stoi(b);
      isRoot[stoi(b)] = false;
    }
  }
  int root = 0;
  while (!isRoot[root])  root++;
  dfs(root, 1);
  if (maxn == n)
    cout << "YES " << ans;
  else
    cout << "NO " << root;
  return 0;
}