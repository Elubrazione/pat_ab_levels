// SPFA
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v;
  int w;
  Node(int _v, int _w): v(_v), w(_w) {}
};
const int MAX = 0x3fffffff;
vector<bool> inq;
vector<int> team, d, innum;
vector<set<int>> pre;
vector<vector<Node>> Adj;
int n, m, c1, c2;

bool SPFA(int s) {
  d.resize(n, MAX);
  inq.resize(n, false);
  innum.resize(n, 0);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  inq[s] = true;
  innum[s]++;
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
          innum[p.v]++;
          if (innum[p.v] >= n)
            return false;
        }
      } else if (d[u] + p.w == d[p.v]) {
        pre[p.v].insert(u);
      }
    }
  }
  return true;
}

int cnt = 0, maxSum = INT_MIN;
vector<int> tempPath, ansPath;
void dfs(int v) {
  if (v == c1) {
    tempPath.push_back(v);
    int curSum = 0;
    for (int i = tempPath.size() - 1; i >= 0; i--)
      curSum += team[tempPath[i]];
    if (curSum > maxSum) {
      maxSum = curSum;
      ansPath = tempPath;
    }
    cnt++;
    tempPath.pop_back();
    return;
  }
  tempPath.push_back(v);
  for (auto p: pre[v])
    dfs(p);
  tempPath.pop_back();
  return;
}

int main() {
  cin >> n >> m >> c1 >> c2;
  pre.resize(n);
  team.resize(n);
  Adj.resize(n);
  for (int i = 0; i < n; i++)
    cin >> team[i];
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    Adj[u].push_back(Node(v, w));
    Adj[v].push_back(Node(u, w));
  }
  bool flag = SPFA(c1);
  if (!flag)  cout << "No Solution!";
  else {
    dfs(c2);
    cout << cnt << " " << maxSum;
  }
  return 0;
}