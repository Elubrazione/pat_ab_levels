#include <bits/stdc++.h>
using namespace std;
int n, d = 0, maxD = 0;
vector<int> vis, ans;
vector<vector<int>> G;

void dfs(int a, int depth) {
  vis[a] = true;
  d = max(d, depth);
  for (int i = 0; i < G[a].size(); i++) {
    if (vis[G[a][i]] == false) {
      dfs(G[a][i], depth + 1);
    }
  }
  return;
}

int main() {
  cin >> n;
  G.resize(n + 1);
  vis.resize(n + 1, false);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      dfs(i, 1);
      cnt++;
    }
  }
  if (cnt > 1)
    cout << "Error: " << cnt << " components";
  else {
    for (int i = 1; i <= n; i++) {
      // 注意这里不能用vis.resize(n + 1, false)
      // 大小已经为(n + 1)，不会进行重置，无法改变vis的值
      fill(vis.begin(), vis.end(), false);
      d = 0;
      dfs(i, 1);
      if (d >= maxD) {
        if (d > maxD) {
          ans.clear();
          maxD = d;
        }
        ans.push_back(i);
      }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i != ans.size() - 1)
        cout << endl;
    }
  }
  return 0;
}