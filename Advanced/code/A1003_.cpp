// BellmanFord + DFS || BellmanFord
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v;
  int dis;
  Node(int _v, int _dis): v(_v), dis(_dis) {}
};
int n, m, c1, c2;
vector<int> team, d, t, num;
vector<set<int>> pre;
vector<vector<Node>> Adj;

bool Bellman_Ford(int s) {
  d[s] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for (int k = 0; k < Adj[u].size(); k++) {
        if (d[u] == INT_MAX)  continue;
        int v = Adj[u][k].v;
        int dtc = Adj[u][k].dis;
        if (d[u] + dtc < d[v]) {
          d[v] = d[u] + dtc;
          pre[v].clear();
          pre[v].insert(u);
        } else if (d[u] + dtc == d[v]) {
          pre[v].insert(u);
        }
      }
    }
  }
  for (int u = 0; u < n; u++) {
    for (int k = 0; k < Adj[u].size(); k++) {
      int v = Adj[u][k].v;
      int dtc = Adj[u][k].dis;
      if (d[u] + dtc < d[v])
        return false;
    }
  }
  return true;
}

int maxSum = INT_MIN, cnt = 0;
vector<int> tempPath, ansPath;
void dfs(int v) {
  if (v == c1) {
    tempPath.push_back(v);
    int curSum = 0;
    for (int i = tempPath.size() - 1; i >= 0; i--) {
      curSum += team[tempPath[i]];
    }
    if (curSum > maxSum) {
      maxSum = curSum;
      ansPath = tempPath;
    }
    cnt++;
    tempPath.pop_back();
    return;
  }
  tempPath.push_back(v);
  set<int>::iterator it;
  for (it = pre[v].begin(); it != pre[v].end(); it++) {
    dfs(*it);
  }
  tempPath.pop_back();
  return;
}

int main() {
  cin >> n >> m >> c1 >> c2;
  // t.resize(n, 0);
  // num.resize(n, 0);
  d.resize(n, INT_MAX);
  pre.resize(n);
  Adj.resize(n);
  for (int i = 0; i < n; i++) {
    int cur;
    cin >> cur;
    team.push_back(cur);
  }
  for (int i = 0; i < m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    Adj[u].push_back(Node(v, l));
    Adj[v].push_back(Node(u, l));
  }
  bool flag = Bellman_Ford(c1);
  // bool flag = Single_Bellman_Ford(c1);
  if (!flag) {
    cout << "No Solution";
    return 0;
  }
  // cout << num[c2] << " " << t[c2];
  dfs(c2);
  cout << cnt << " " << maxSum;
  return 0;
}



// 不用dfs，直接在bellman里面求解第二标准
bool Single_Bellman_Ford(int s) {
  d[s] = 0;
  t[s] = team[s];
  num[s] = 1;
  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for(auto p: Adj[u]) {
        // INT_MAX一定要跳过，否则会发生正溢出
        // 不想写这个continue可以把d数组的最大值初始化为0x3fffffff
        if (d[u] == INT_MAX)
          continue;
        if(d[p.v] > d[u] + p.dis) {
          d[p.v] = d[u] + p.dis;
          num[p.v] = num[u];
          t[p.v] = t[u] + team[p.v];
          pre[p.v].clear();
          pre[p.v].insert(u);
        }
        else if(d[p.v] == d[u] + p.dis) {
          t[p.v] = max(t[u] + team[p.v], t[p.v]);
          pre[p.v].insert(u);
          num[p.v] = 0;
          for(auto k: pre[p.v])
            num[p.v] += num[k];
        }
      }
    }
  }
  for (int u = 0; u < n; u++) {
    for (auto p: Adj[u]) {
      if(d[p.v] > d[u] + p.dis)
        return false;
    }
  }
  return true;
}