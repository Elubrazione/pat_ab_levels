#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> G;
vector<bool> vis;
vector<int> father;

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
  int faA = findFather(a);
  int faB = findFather(b);
  if (faA != faB)
    father[faA] = father[faB];
  return;
}

void init() {
  for (int i = 1; i <= n; i++) {
    father[i] = i;
    vis[i] = false;
  }
  return;
}

int main(){
  cin >> n >> m >> k;
  vis.resize(n + 1);
  father.resize(n + 1);
  G.resize(n + 1);

  int a, b, cur;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 0; i < k; i++) {
    cin >> cur;
    init();
    for (int v = 1; v <= n; v++) {
      for (auto u: G[v]) {
        if (v == cur || u == cur) continue;
        Union(v, u);
      }
    }
    int ans = 0;
    // 注意对比和isRoot数组的写法
    for (int j = 1; j <= n; j++) {
      if (j == cur) continue;
      int fa_j = findFather(j);
      if (vis[fa_j] == false) {
        ans++;
        vis[fa_j] = true;
      }
    }
    cout << ans - 1 << endl;
  }
  return 0;
}