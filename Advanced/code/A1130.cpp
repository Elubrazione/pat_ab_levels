#include <bits/stdc++.h>
using namespace std;
struct Node {
  string data;
  int left, right;
};

vector<Node> nodes;
vector<bool> isRoot;

void inTraversal(int k, int root) {
  if (k == -1)  return;
  if ((nodes[k].left != -1 || nodes[k].right != -1) && k != root)
    cout << "(";
  inTraversal(nodes[k].left, root);
  cout << nodes[k].data;
  inTraversal(nodes[k].right, root);
  if ((nodes[k].left != -1 || nodes[k].right != -1) && k != root)
    cout << ")";
}

int main() {
  int n, a, b, i;
  cin >> n;
  nodes.resize(n + 1);
  isRoot.resize(n + 1, false);

  for (i = 1; i <= n; i++) {
    cin >> nodes[i].data >> nodes[i].left >> nodes[i].right;
    if (nodes[i].left != -1)  isRoot[nodes[i].left] = true;
    if (nodes[i].right != -1) isRoot[nodes[i].right] = true;
  }
  i = 1;
  while (isRoot[i]) i++;
  // printf("root is %d\n", i);
  inTraversal(i, i);
  cout << endl;
  return 0;
}