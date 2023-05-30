#include <bits/stdc++.h>
using namespace std;
int m, n, l, p;
vector<vector<vector<int>>> slices;
vector<int> X = { 0, 0, 0, 0, -1, 1 };
vector<int> Y = { 1, -1, 0, 0, 0, 0 };
vector<int> Z = { 0, 0, 1, -1, 0, 0 };

int bfs(int x, int y, int z) {
  queue<vector<int>> q;
  int tot = 0;
  q.push({x, y, z});
  slices[x][y][z] = 0;
  while(!q.empty()) {
    vector<int> cur = q.front();
    q.pop();
    tot++;
    for (int i = 0; i < 6; i++) {
      int newx = cur[0] + X[i], newy = cur[1] + Y[i], newz = cur[2] + Z[i];
      if (newx < 0 || newy < 0 || newz < 0 || newx >= m || newy >= n || newz >= l || !slices[newx][newy][newz])
        continue;
      q.push({newx, newy, newz});
      slices[newx][newy][newz] = 0;
    }
  }
  if (tot >= p)  return tot;
  else    return 0;
}

int main() {
  int ans = 0;
  cin >> m >> n >> l >> p;
  slices.resize(m, vector<vector<int>>(n, vector<int>(l)));
  for (int k = 0; k < l; k++)
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> slices[i][j][k];

  for (int k = 0; k < l; k++)
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (slices[i][j][k] == 1)
        ans += bfs(i, j, k);
  cout << ans;
  return 0;
}