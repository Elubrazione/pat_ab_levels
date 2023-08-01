/**
 * 使用了SPFA算法计算，第二标准为边权
 * 前驱结点的保存时采用了pair数据结构来同时保存边权
 * 在数据量大（最后一个测试点）时，使用邻接表空间消耗大概是邻接矩阵的一半
 * 时间开销不再赘述，Shortest Path Faster Algorithm
 */

# include <bits/stdc++.h>
using namespace std;

struct Node {
  int v, w, c;
  Node(int _v, int _w, int _c): v(_v), w(_w), c(_c) {}
};

int n, m, st, ed;
vector<bool> inq;
vector<int> d;
vector<set<pair<int, int>>> pre;
vector<vector<Node>> Adj;
const int MAX = 0x3fffffff;

void SPFA(int s) {
  d.resize(n, MAX);
  inq.resize(n, false);
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
        pre[p.v].insert(make_pair(u, p.c));
        if (!inq[p.v]) {
          q.push(p.v);
          inq[p.v] = true;
        }
      } else if (d[u] + p.w == d[p.v]) {
        pre[p.v].insert(make_pair(u, p.c));
      }
    }
  }
  return;
}

/**
 * If such a shortest path is not unique,
 * you are supposed to output the one with the minimum cost,
 * which is guaranteed to be unique.
*/
int ansCost = INT_MAX;
vector<pair<int, int>> tempPath, ansPath;
void dfs(pair<int, int> v) {
  tempPath.push_back(v);
  if (v.first == st) {
    int cost = 0;
    // 注意这里是从起始点（最后一个元素）到倒二个元素，计算边权
    for (int i = tempPath.size() - 1; i > 0; i--) {
      cost += tempPath[i].second;
    }
    if (cost < ansCost) {
      ansCost = cost;
      ansPath = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  for (auto p: pre[v.first])
    dfs(p);
  tempPath.pop_back();
  return;
}

int main() {
  cin >> n >> m >> st >> ed;
  pre.resize(n);
  Adj.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    Adj[u].push_back(Node(v, w, c));
    Adj[v].push_back(Node(u, w, c));
  }
  SPFA(st);
  dfs(make_pair(ed, 0));
  for (int i = ansPath.size() - 1; i >= 0; i--)
    cout << ansPath[i].first << " ";
  printf("%d %d", d[ed], ansCost);
  return 0;
}