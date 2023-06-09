#include <bits/stdc++.h>
using namespace std;
int maxn = 100005;

struct Node {
  int addr, val, next;
  bool flag;
};
vector<Node> node(maxn);

int main() {
  for (int i = 0; i < maxn; i++)
    node[i].flag = false;
  int n, head;
  cin >> n >> head;
  int t1;
  for (int i = 0; i < n; i++) {
    cin >> t1;
    cin >> node[t1].val >> node[t1].next;
    node[t1].addr = t1;
  }
  int count = 0;
  for (int p = head; p != -1; p = node[p].next) {
    node[p].flag = true;
    count++;
  }
  if (!count) {
    cout << "0 -1";
    return 0;
  }
  sort(node.begin(), node.end(), [&](Node a, Node b) {
    if (a.flag == false || b.flag == false) {
      return a.flag > b.flag;
    } else {
      return a.val < b.val;
    }
  });
  printf("%d %05d\n", count, node[0].addr);
  for (int i = 0; i < count; i++) {
    if (i != count - 1)
      printf("%05d %d %05d\n", node[i].addr, node[i].val, node[i+1].addr);
    else
      printf("%05d %d -1", node[i].addr, node[i].val);
  }
  return 0;
}