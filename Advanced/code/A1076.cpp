#include <bits/stdc++.h>
using namespace std;
int n, l;
vector<int> vis;
vector<vector<int>> G;

// 使用DFS遍历很容易出错，因为需要注意一种情况，
// 即可能有一个用户X在第i次被访问，但是此时已经达到转发层数上限，故无法继续遍历。
// 但若该用户可以通过另一条路径更快地被访问到，那么是可以继续深入遍历的。
void dfs(int a, int depth, int &tot) {
  vis[a] = true;
  if (depth > l)  return;
  for (int i = 0; i < G[a].size(); i++) {
    int v = G[a][i];
    // cout << v << endl;
    if (vis[v] == false) {
      tot++;
      dfs(v, depth + 1, tot);
    }
  }
}

void bfs(int a, int &tot) {
  queue<int> q;
  q.push(a);
  vis[a] = true;
  int layer = -1;
  while (!q.empty()) {
    int num = q.size();
    layer++;
    if (layer > l)  return;
    for(int i = 0; i < num; i++) {
      int cur = q.front();
      q.pop();
      if (layer)  tot++;  // layer=0时访问的是发博的用户本身，不计入
      for (int j = 0; j < G[cur].size(); j++)
        if (vis[G[cur][j]] == false) {
          vis[G[cur][j]] = true;
          q.push(G[cur][j]);
        }
    }
  }
}

int main() {
  cin >> n >> l;
  int num, k;
  G.resize(n + 1);
  vis.resize(n + 1, false);
  for (int i = 1; i <= n; i++) {
    cin >> num;
    for (int j = 1; j <= num; j++) {
      cin >> k;
      G[k].push_back(i);
    }
  }
  cin >> num;
  for (int i = 0; i < num; i++) {
    fill(vis.begin(), vis.end(), false);
    cin >> k;
    int tot = 0;
    bfs(k, tot);
    cout << tot;
    if (i != num - 1)  cout << endl;
  }
  return 0;
}