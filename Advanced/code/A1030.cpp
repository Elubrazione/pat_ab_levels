#include <bits/stdc++.h>
using namespace std;
int n, m, e, s, minCost = INT_MAX;
vector<int> d, vis, tempPath, path;
vector<vector<int>> pre;

struct Node {
  int w;
  int c;
  Node(int _w, int _c): w(_w), c(_c) {}
};
vector<vector<Node>> G;

void Dijkstra(int s) {
  d[s] = 0;
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
      if (vis[v] == false && G[u][v].w != INT_MAX) {
        if (d[u] + G[u][v].w < d[v]) {
          d[v] = d[u] + G[u][v].w;
          pre[v].clear();
          pre[v].push_back(u);
        } else if (d[u] + G[u][v].w == d[v]) {
          pre[v].push_back(u);
        }
      }
    }
  }
  return;
}

void dfs(int v) {
  if (v == s) {
    tempPath.push_back(v);
    int cost = 0;
    for (int i = tempPath.size() - 1; i > 0; i--) {
      int id = tempPath[i], nxt = tempPath[i-1];
      cost += G[id][nxt].c;
    }
    // printf("cost %d %d\n", cost, minCost);
    if (cost < minCost) {
      minCost = cost;
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
  cin >> n >> m >> s >> e;
  pre.resize(n);
  d.resize(n, INT_MAX);
  vis.resize(n, false);
  G.resize(n, vector<Node>(n, Node(INT_MAX, INT_MAX)));
  for (int i = 0; i < m; i++) {
    int u, v, dtc, cst;
    cin >> u >> v >> dtc >> cst;
    G[u][v] = Node(dtc, cst);
    G[v][u] = Node(dtc, cst);
  }
  Dijkstra(s);
  dfs(e);
  for (int i = path.size() - 1; i >= 0; i--)
    cout << path[i] << " ";
  printf("%d %d", d[e], minCost);
  return 0;
}