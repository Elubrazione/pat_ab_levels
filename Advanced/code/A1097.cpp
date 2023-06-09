#include <bits/stdc++.h>
using namespace std;
int maxn = 100005;

struct Node {
  int addr, val, next;
  int order;
};
vector<Node> node(maxn);

int main() {
  for (int i = 0; i < maxn; i++)
    node[i].order = maxn * 2;
  int head, n;
  cin >> head >> n;
  int t1;
  for (int i = 0; i < n; i++) {
    cin >> t1;
    cin >> node[t1].val >> node[t1].next;
    node[t1].addr = t1;
  }
  int count1 = 0, count2 = 0;
  vector<bool> fg(10001, false);
  for (int p = head; p != -1; p = node[p].next) {
    if (fg[abs(node[p].val)] == false) {
      node[p].order = count1++;
      fg[abs(node[p].val)] = true;
    } else {
      node[p].order = maxn + count2++;
    }
  }
  if (!(count1 + count2)) {
    cout << "0 -1";
    return 0;
  }
  sort(node.begin(), node.end(), [&](Node a, Node b) {
    return a.order < b.order;
  });
  for (int i = 0; i < count1 + count2; i++) {
    if (i != count1 - 1 && i != count1 + count2 - 1)
      printf("%05d %d %05d\n", node[i].addr, node[i].val, node[i+1].addr);
    else
      printf("%05d %d -1", node[i].addr, node[i].val);
    if (i == count1 - 1)  cout << endl;
  }
  return 0;
}