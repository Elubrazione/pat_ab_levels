# include <bits/stdc++.h>
using namespace std;
int n, m, c1, c2;
vector<int> team, t, vis, d, num;
vector<vector<int>> G;

void Dijkstra(int s) {
  d[s] = 0;
  num[s] = 1;
  t[s] = team[s];
  for (int i = 0; i < n; i++) {
    int u = -1, mx = INT_MAX;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && G[u][v] != INT_MAX) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = G[u][v] + d[u];
          num[v] = num[u];
          t[v] = t[u] + team[v];
        } else if (d[u] + G[u][v] == d[v]) {
          num[v] += num[u];
          t[v] = max(t[v], t[u] + team[v]);
        }
      }
    }
  }
  return;
}

int main() {
  cin >> n >> m >> c1 >> c2;
  t.resize(n, 0);
  num.resize(n, 0);
  d.resize(n, INT_MAX);
  vis.resize(n, false);
  G.resize(n, vector<int>(n, INT_MAX));
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    team.push_back(k);
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    G[a][b] = w;
    G[b][a] = w;
  }
  Dijkstra(c1);
  cout << num[c2] << " " << t[c2];
  return 0;
}