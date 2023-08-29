#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;

int main() {
  int n, m, v1, v2, k, cur, num;
  cin >> n >> m;
  G.resize(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    G[v1][v2] = 1;
    G[v2][v1] = 1;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    bool flag = true;
    cin >> num;
    vector<int> v(num);
    set<int> s;
    for (int j = 0; j < num; j++) {
      cin >> v[j];
      s.insert(v[j]);
    }
    if (s.size() != n || num != n + 1 || v[0] != v[num-1])  flag = false;
    for (int j = 0; j < num - 1; j++)
      if (!G[v[j]][v[j+1]]) flag = false;
    printf("%s\n", flag? "YES": "NO");
  }
  return 0;
}