#include <bits/stdc++.h>
using namespace std;
vector<int> degree;
vector<bool> vis;
vector<vector<int>> G;

void dfs(int u, int n) {
  vis[u] = true;
  for (int i = 1; i <= n; i++) {
    if (G[u][i] == 1 && vis[i] == false)
      dfs(i, n);
  }
}

int printDegree(int n) {
  int num = degree[1]%2? 0: 1;
  cout << degree[1];
  for (int i = 2; i <= n; i++) {
    cout << " " << degree[i];
    if (!(degree[i] % 2))  num++;
  }
  cout << endl;
  if (num == n)  return 2;
  else if (num + 2 == n)  return 1;
  else  return 0;
}

int main() {
  int n, m, a, b, cnt = 0;
  cin >> n >> m;
  vis.resize(n + 1, false);
  degree.resize(n + 1);
  G.resize(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a][b] = 1;
    G[b][a] = 1;
    degree[a]++;
    degree[b]++;
  }
  int isEulerian = printDegree(n);
  for (int i = 1; i <= n; i++)
    if (vis[i] == false) {
      dfs(i, n);
      cnt++;
    }
  if (cnt == 1) {
    if (isEulerian == 2)  cout << "Eulerian";
    else if (isEulerian == 1)  cout << "Semi-Eulerian";
    else  cout << "Non-Eulerian";
  } else {
    cout << "Non-Eulerian";
  }
  return 0;
}