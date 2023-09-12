#include <bits/stdc++.h>
using namespace std;
struct Node {
  int val, cnt, id;
  friend bool operator < (Node a, Node b) {
    return a.cnt == b.cnt? a.id > b.id: a.cnt > b.cnt;
  }
};
set<Node> q1, q2;
int hash1[10001], hash2[10001], hash3[10001], hash4[10001];

int main() {
  int k, n, m, cur;
  cin >> k >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &cur);
    if (hash3[cur] != 0) {  // cache命中
      auto it = q2.find(Node{cur, hash3[cur], hash4[cur]});
      q2.erase(it);
      hash3[cur]++;
      hash4[cur] = i;
      q2.insert(Node{cur, hash3[cur], hash4[cur]});
    } else {  // cache不命中
      if (hash1[cur] == 0) {  // 历史队列不命中，插入
        if (q1.size() == k) {
          q1.erase(*(q1.begin()));  // 历史队列无空位
          hash1[q1.begin()->val] = 0;
          hash2[q1.begin()->val] = 0;
        }
        q1.insert(Node{cur, 1, i});
        hash1[cur] = 1;
        hash2[cur] = i;
      } else {  // 历史队列命中
        auto it = q1.find(Node{cur, hash1[cur], hash2[cur]});
        q1.erase(it);
        if (hash1[cur] == k - 1) {  // 进cache
          hash1[cur] = 0;
          hash2[cur] = 0;
          if (q2.size() == k) {  // cache满，替换
            q2.erase(*(q2.begin()));
            hash3[q2.begin()->val] = 0;
            hash4[q2.begin()->val] = 0;
          }
          q2.insert(Node{cur, 1, cur});
          hash3[cur] = 1;
          hash4[cur] = i;
        } else {  // 不进cache，进历史队列
          hash1[cur]++;
          hash2[cur] = i;
          q1.insert(Node{cur, hash1[cur], hash2[cur]});
        }
      }
    }
  }
  if (q2.empty()) {
    cout << "-" << endl;
    return 0;
  }
  for (auto it = q2.end(); it != q2.begin(); it--) {
    printf("%d", *(it));
    if (it != q2.begin()) cout << " ";
  }
  return 0;
}