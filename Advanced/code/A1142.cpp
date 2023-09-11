#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> vis;

int judge(vector<int> &clique, int n) {
  for (int i = 0; i < clique.size() - 1; i++) {
    for (int j = i + 1; j < clique.size(); j++) {
      if (G[clique[i]][clique[j]] != 1)
        return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    int cnt = 0;
    for (auto q: clique)
      if (G[i][q] == 1) cnt++;
    if (cnt == clique.size()) return 1;
  }
  return 2;
}

int main() {
  int n, m, a, b, k;
  cin >> n >> m;
  G.resize(n + 1, vector<int>(n + 1));
  vis.resize(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    G[a][b] = 1;
    G[b][a] = 1;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> a;
    vector<int> clique;
    fill(vis.begin(), vis.end(), false);
    for (int j = 0; j < a; j++) {
      cin >> b;
      clique.push_back(b);
      vis[b] = true;
    }
    int ans = judge(clique, n);
    if (ans == 2) printf("Yes\n");
    else if (ans == 1)  printf("Not Maximal\n");
    else  printf("Not a Clique\n");
  }
  return 0;
}