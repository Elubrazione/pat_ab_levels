#include <bits/stdc++.h>
using namespace std;
int cmax, n, sp, m;
int minNeed = INT_MAX, minRemain = INT_MAX;
vector<vector<int>> G, pre;
vector<int> bike, d, vis, path, tempPath;

void Dijkstra(int s) {
  d[s] = 0;
  for (int i = 0; i <= n; i++) {
    int u = -1, mx = INT_MAX;
    for (int j = 0; j <= n; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (int v = 0; v <= n; v++) {
      if (vis[v] == false && G[u][v] != INT_MAX) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if (d[u] + G[u][v] == d[v]) {
          pre[v].push_back(u);
        }
      }
    }
  }
  return;
}

void dfs(int v) {
  if (v == 0) {
    tempPath.push_back(v);
    int need = 0, remain = 0;
    for (int i = tempPath.size() - 1; i >= 0; i--) {
      int cur = tempPath[i];
      if (bike[cur] > 0) {
        remain += bike[cur];
      } else {
        if (remain > abs(bike[cur]))
          remain -= abs(bike[cur]);
        else {
          need += abs(bike[cur]) - remain;
          remain = 0;
        }
      }
    }
    if (need < minNeed || (need == minNeed && remain < minRemain)) {
      minNeed = need;
      minRemain = remain;
      path = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  tempPath.push_back(v);
  for (int i = 0; i < pre[v].size(); i++)
    dfs(pre[v][i]);
  tempPath.pop_back();
  return;
}

int main() {
  cin >> cmax >> n >> sp >> m;
  pre.resize(n + 1);
  d.resize(n + 1, INT_MAX);
  bike.resize(n + 1, 0);
  vis.resize(n + 1, false);
  G.resize(n + 1, vector<int>(n + 1, INT_MAX));
  for (int i = 1; i <= n; i++) {
    cin >> bike[i];
    bike[i] -= cmax / 2;
  }
  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    G[a][b] = t;
    G[b][a] = t;
  }
  Dijkstra(0);
  dfs(sp);
  cout << minNeed << " ";
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i];
    if (i > 0)  cout << "->";
  }
  cout << " " << minRemain;
  return 0;
}