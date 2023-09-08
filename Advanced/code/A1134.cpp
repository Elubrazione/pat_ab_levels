#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b, k, num;
  cin >> n >> m;
  vector<int> v[n];
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(i);
    v[b].push_back(i);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> num;
    int flag = 0;
    vector<int> hash1(m, 0);
    for (int j = 0; j < num; j++) {
      cin >> a;
      for (auto p: v[a])
        hash1[p] = 1;
    }
    for (auto p: hash1) {
      if (!p) {
        cout << "No" << endl;
        flag = 1;
        break;
      }
    }
    if (!flag)  cout << "Yes" << endl;
  }
  return 0;
}