#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> G, temp;

void dfs(int a) {
  temp[a][a] = INT_MAX;
  for (int i = 1; i <= n; i++) {
    if (temp[i][i] == 1 && temp[a][i] != INT_MAX) {
      dfs(i);
    }
  }
  return;
}

int main() {
  cin >> n >> m >> k;
  G.resize(n + 1, vector<int>(n + 1, INT_MAX));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    G[a][b] = 1;
    G[b][a] = 1;
  }
  for (int i = 0; i < k; i++) {
    int cur;
    cin >> cur;
    temp = G;
    for (int j = 1; j <= n; j++) {
      temp[j][j] = 1;
      if (temp[j][cur] != INT_MAX) {
        temp[j][cur] = INT_MAX;
        temp[cur][j] = INT_MAX;
      }
    }
    int ans = 0;
    for (int i = 1; i <=n; i++) {
      if (temp[i][i] == 1) {
        dfs(i);
        ans++;
      }
    }
    cout << ans - 1;
    if (i < k - 1)  cout << endl;
  }
  return 0;
}