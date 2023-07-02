#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v;
  int w;
  Node(int _v, int _w): v(_v), w(_w) {}
};

const int MAX = 0x3fffffff;
int cmax, n, sp, m;
vector<bool> inq;
vector<int> bike, d;
vector<set<int>> pre;
vector<vector<Node>> Adj;

// 已知不存在负环可以去掉记录入队次数的num数组
void SPFA(int s) {
  inq.resize(n + 1, false);
  d.resize(n + 1, MAX);
  queue<int> q;
  q.push(s);
  inq[s] = true;
  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (auto p: Adj[u]) {
      if (d[u] + p.w < d[p.v]) {
        d[p.v] = d[u] + p.w;
        pre[p.v].clear();
        pre[p.v].insert(u);
        if (!inq[p.v]) {
          q.push(p.v);
          inq[p.v] = true;
        }
      } else if (d[u] + p.w == d[p.v]) {
        pre[p.v].insert(u);
      }
    }
  }
  return;
}

/**
 * If there are more than one shortest path,
 * the one that requires the least number of bikes sent from PBMC will be chosen.
 * If such a path is still not unique, output the one that requires minimum
 * number of bikes that we must take back to PBMC.
 */
int ansNeed = INT_MAX, ansRemain = INT_MAX;
vector<int> tempPath, ansPath;
void dfs(int v) {
  tempPath.push_back(v);
  if (v == 0) {
    int remain = 0, need = 00;
    for (int i = tempPath.size() - 1; i >= 0; i--) {
      int u = tempPath[i];
      if (bike[u] > 0) {
        remain += bike[u];
      } else {
        if (remain > abs(bike[u]))
          remain -= abs(bike[u]);
        else {
          need += abs(bike[u]) - remain;
          remain = 0;
        }
      }
    }
    if (need < ansNeed || (need == ansNeed && remain < ansRemain)) {
      ansNeed = need;
      ansRemain = remain;
      ansPath = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  for (auto p: pre[v])
    dfs(p);
  tempPath.pop_back();
  return;
}

int main() {
  cin >> cmax >> n >> sp >> m;
  Adj.resize(n + 1);
  pre.resize(n + 1);
  bike.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> bike[i];
    bike[i] -= cmax / 2;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    Adj[u].push_back(Node(v, w));
    Adj[v].push_back(Node(u, w));
  }
  SPFA(0);
  dfs(sp);
  cout << ansNeed << " ";
  for (int i = ansPath.size() - 1; i >= 0; i--) {
    cout << ansPath[i];
    if (i)  cout << "->";
  }
  cout << " " << ansRemain;
  return 0;
}