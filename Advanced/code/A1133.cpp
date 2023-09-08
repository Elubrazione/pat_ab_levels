#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
struct Node {
  int addr, data, next;
  int order;
};
vector<Node> node(maxn);

int main() {
  int begin, n, k, temp;
  cin >> begin >> n >> k;
  for (int i = 0; i < maxn; i++)
    node[i].order = maxn * 3;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    cin >> node[temp].data >> node[temp].next;
    node[temp].addr = temp;
  }
  int negCnt = 0, lowerkCnt = 0, cnt = 0, total;
  for (int p = begin; p != -1; p = node[p].next) {
    if (node[p].data < 0) {
      node[p].order = negCnt++;
    } else if (node[p].data <= k) {
      node[p].order = maxn + lowerkCnt++;
    } else {
      node[p].order = maxn * 2 + cnt++;
    }
  }
  sort(node.begin(), node.end(), [&] (Node a, Node b) {
    return a.order < b.order;
  });
  total = negCnt + lowerkCnt + cnt;
  for (int i = 0; i < total; i++) {
    if (i != total - 1) {
      printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
    } else {
      printf("%05d %d -1", node[i].addr, node[i].data);
    }
  }
  return 0;
}