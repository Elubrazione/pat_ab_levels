#include <bits/stdc++.h>
using namespace std;
struct Node {
  int value, cnt;
  friend bool operator < (const Node &a, const Node &b) {
    return (a.cnt != b.cnt)? a.cnt > b.cnt: a.value < b.value;
  }
};
int hash1[50001];
set<Node> s;

int main() {
  int n, k, num;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (i) {
      printf("%d:", num);
      int count = 0;
      for (auto it = s.begin(); count < k && it != s.end(); it++) {
        printf(" %d", it -> value);
        count++;
      }
      cout << endl;
    }
    auto it = s.find(Node{num, hash1[num]});
    if (it != s.end())  s.erase(it);
    hash1[num]++;
    s.insert(Node{num, hash1[num]});
  }
  return 0;
}