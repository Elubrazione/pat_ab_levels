#include <bits/stdc++.h>
using namespace std;
int n, maxh = 0;
set<int> s;
vector<bool> isRoot, vis;
vector<int> father, temp;
vector<vector<int>> G;

void dfs(int node, int height) {
  if (height > maxh) {
    temp.clear();
    temp.push_back(node);
    maxh = height;
  } else if (height == maxh) {
    temp.push_back(node);
  }
  vis[node] = true;
  for (auto v: G[node])
    if (vis[v] == false)
      dfs(v, height + 1);
  return;
}

int findFather(int x) {
  int a = x;
  while (x != father[x])
    x = father[x];
  while (a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

void Union(int a, int b) {
  int fa_a = findFather(a);
  int fa_b = findFather(b);
  if (fa_a != fa_b)
    father[fa_a] = father[fa_b];
  return;
}

void init() {
  for (int i = 1; i <= n; i++)
    father[i] = i;
  return;
}

int main() {
  cin >> n;
  vis.resize(n + 1, false);
  isRoot.resize(n + 1, false);
  father.resize(n + 1);
  G.resize(n + 1);
  init();

  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    Union(a, b);
  }

  // calculate blocks
  int ans = 0;
  for (int i = 1; i <= n; i++)
    isRoot[findFather(i)] = true;
  for (int i = 1; i <= n; i++)
    ans += isRoot[i];

  if (ans > 1) {
    printf("Error: %d components", ans);
  } else {
    dfs(1, 1);
    for (auto p: temp)  s.insert(p);
    fill(vis.begin(), vis.end(), false);
    dfs(temp[0], 1);
    for (auto p: temp)  s.insert(p);
    for (auto p: s) cout << p << endl;
  }
  return 0;
}