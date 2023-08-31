#include <bits/stdc++.h>
using namespace std;

vector<bool> winner;
vector<vector<int>> info;
set<int> w;
vector<int> pool;
bool mp[100001], mp2[100001];

int main() {
  int n, m, a, b, cur;
  cin >> a >> b;
  pool.push_back(a);
  pool.push_back(b);
  mp[abs(a-b)] = true;
  mp2[a] = mp2[b] = true;

  cin >> n >> m;
  winner.resize(n, true);
  info.resize(m, vector<int>(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &info[j][i]);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!winner[j]) continue;
      if (mp[info[i][j]] && !mp2[info[i][j]]) {
        for (auto p: pool)
          mp[abs(p-info[i][j])] = true;
        pool.push_back(info[i][j]);
        mp2[info[i][j]] = true;
      } else {
        printf("Round #%d: %d is out.\n", i + 1, j + 1);
        winner[j] = false;
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (winner[i])  w.insert(i + 1);
  if (!w.size()) cout << "No winner.";
  else {
    printf("Winner(s):");
    for (auto p: w) printf(" %d", p);
  }
  return 0;
}