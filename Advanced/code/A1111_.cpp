// spfa+dfs，待封装
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v;
  int dis;
  int time;
  Node(int _v, int _dis, int _time): v(_v), dis(_dis), time(_time) {}
};
bool operator< (const Node & x, const Node & y) {
  return x.v < y.v;
}

const int MAXN = 0x3fffffff;
int n, m, s, e;
vector<int> vis, d, inq;
vector<vector<Node>> Adj;
vector<set<Node>> pre;
vector<Node> tempPath, ansPath_1, ansPath_2;

void spfa_for_distance(int s) {
  d.resize(n, MAXN);
  inq.resize(n, false);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  inq[s] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (auto p: Adj[u]) {
      if (d[u] + p.dis < d[p.v]) {
        d[p.v] = d[u] + p.dis;
        pre[p.v].clear();
        pre[p.v].insert(Node(u, p.dis, p.time));
        if (!inq[p.v]) {
          q.push(p.v);
          inq[p.v] = true;
        }
      } else if (d[u] + p.dis == d[p.v]) {
        pre[p.v].insert(Node(u, p.dis, p.time));
      }
    }
  }
  return;
}

int minTime = MAXN;
void dfs_for_distance(Node cur) {
  tempPath.push_back(cur);
  if (cur.v == s) {
    int curTime = 0;
    for (int i = tempPath.size() - 1; i > 0; i--)
      curTime += tempPath[i].time;
    if (curTime < minTime) {
      minTime = curTime;
      ansPath_1 = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  set<Node>::iterator it;
  for (it = pre[cur.v].begin(); it != pre[cur.v].end(); it++)
    dfs_for_distance(*it);
  tempPath.pop_back();
  return;
}

void spfa_for_time(int s) {
  fill(d.begin(), d.end(), MAXN);
  fill(inq.begin(), inq.end(), false);
  fill(vis.begin(), vis.end(), false);
  for (auto p: pre) p.clear();
  tempPath.clear();

  d[s] = 0;
  queue<int> q;
  q.push(s);
  inq[s] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (auto p: Adj[u]) {
      if (d[u] + p.time < d[p.v]) {
        d[p.v] = d[u] + p.time;
        pre[p.v].clear();
        pre[p.v].insert(Node(u, p.dis, p.time));
        if (!inq[p.v]) {
          q.push(p.v);
          inq[p.v] = true;
        }
      } else if (d[u] + p.time == d[p.v]) {
        pre[p.v].insert(Node(u, p.dis, p.time));
      }
    }
  }
  return;
}

int minNum = MAXN;
void dfs_for_time(Node cur) {
  tempPath.push_back(cur);
  if (cur.v == s) {
    if (tempPath.size() < minNum) {
      minNum = tempPath.size();
      ansPath_2 = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  set<Node>::iterator it;
  for (it = pre[cur.v].begin(); it != pre[cur.v].end(); it++)
    dfs_for_time(*it);
  tempPath.pop_back();
  return;
}

int main() {
  cin >> n >> m;
  Adj.resize(n);
  pre.resize(n);
  vis.resize(n, false);

  int ansDis = 0, ansTime = 0;
  int v1, v2, flag, len, tt;
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2 >> flag >> len >> tt;
    Adj[v1].push_back(Node(v2, len, tt));
    if (flag != 1)
      Adj[v2].push_back(Node(v1, len, tt));
  }
  cin >> s >> e;
  spfa_for_distance(s);
  dfs_for_distance(Node(e, 0, 0));
  for (int i = ansPath_1.size() - 1; i > 0; i--)
    ansDis += ansPath_1[i].dis;
  spfa_for_time(s);
  dfs_for_time(Node(e, 0, 0));
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