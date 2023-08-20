#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v;
  int dis;
  int time;
  Node(int _v, int _dis, int _time): v(_v), dis(_dis), time(_time) {}
};
const int MAXN = 0x3fffffff;
int n, m, s, e;
int minTime = MAXN, ansNum = MAXN;
vector<vector<Node>> Adj, pre;
vector<int> d, vis;
vector<Node> ansPath_1, ansPath_2, tempPath;

void Dijkstra_1(int s) {
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, mx = MAXN;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (auto p: Adj[u]) {
      if (vis[p.v] == false) {
        if (d[u] + p.dis < d[p.v]) {
          d[p.v] = d[u] + p.dis;
          pre[p.v].clear();
          pre[p.v].push_back(Node(u, p.dis, p.time));
        } else if (d[u] + p.dis == d[p.v]) {
          pre[p.v].push_back(Node(u, p.dis, p.time));
        }
      }
    }
  }
  return;
}

void dfs_1(Node cur) {
  tempPath.push_back(cur);
  if (cur.v == s) {
    int tempTime = 0;
    for (int i = tempPath.size() - 1; i > 0; i--)
      tempTime += tempPath[i].time;
    if (tempTime < minTime) {
      minTime = tempTime;
      ansPath_1 = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  for (auto p: pre[cur.v])
    dfs_1(p);
  tempPath.pop_back();
  return;
}

void Dijkstra_2(int s) {
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, mx = MAXN;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (auto p: Adj[u]) {
      if (vis[p.v] == false) {
        if (d[u] + p.time < d[p.v]) {
          d[p.v] = d[u] + p.time;
          pre[p.v].clear();
          pre[p.v].push_back(Node(u, p.dis, p.time));
        }
        else if (d[u] + p.time == d[p.v]) {
          pre[p.v].push_back(Node(u, p.dis, p.time));
        }
      }
    }
  }
  return;
}

void dfs_2(Node cur) {
  tempPath.push_back(cur);
  if (cur.v == s) {
    if (tempPath.size() < ansNum) {
      ansNum = tempPath.size();
      ansPath_2 = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  for (auto p: pre[cur.v])
    dfs_2(p);
  tempPath.pop_back();
  return;
}

int main() {
  cin >> n >> m;
  Adj.resize(n);
  pre.resize(n);
  vis.resize(n, false);
  d.resize(n, MAXN);

  int v1, v2, flag, len, tt;
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2 >> flag >> len >> tt;
    Adj[v1].push_back(Node(v2, len, tt));
    if (flag != 1)
      Adj[v2].push_back(Node(v1, len, tt));
  }
  cin >> s >> e;
  int ansDis = 0, ansTime = 0;
  Dijkstra_1(s);
  dfs_1(Node(e, 0, 0));
  for (int i = ansPath_1.size() - 1; i > 0; i--)
    ansDis += ansPath_1[i].dis;

  fill(d.begin(), d.end(), MAXN);
  fill(vis.begin(), vis.end(), false);
  for (auto p: pre)  p.clear();
  tempPath.clear();

  Dijkstra_2(s);
  dfs_2(Node(e, 0, 0));
  for (int i = ansPath_2.size() - 1; i > 0; i--)
    ansTime += ansPath_2[i].time;

  bool fg = false;
  if (ansPath_1.size() == ansPath_2.size()) {
    for (int i = 0; i < ansPath_1.size(); i++) {
      if (ansPath_1[i].v != ansPath_2[i].v) {
        fg = true;
        break;
      }
    }
  } else {
    fg = true;
  }

  if (!fg) {
    printf("Distance = %d; Time = %d: %d", ansDis, ansTime, s);
    for (int i = ansPath_1.size() - 2; i >= 0; i--)
      printf(" -> %d", ansPath_1[i].v);
    return 0;
  }
  printf("Distance = %d: %d", ansDis, s);
  for (int i = ansPath_1.size() - 2; i >= 0; i--)
    printf(" -> %d", ansPath_1[i].v);
  printf("\nTime = %d: %d", ansTime, s);
  for (int i = ansPath_2.size() - 2; i >= 0; i--)
    printf(" -> %d", ansPath_2[i].v);
  return 0;
}