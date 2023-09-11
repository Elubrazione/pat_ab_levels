#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> num;

bool dfs(int i, int j) {
  if (i == 0 || j == 0) return true;
  if (num[i-1][j] == 0) return dfs(i - 1, j);
  else if (num[i][j-1] == 0)  return dfs(i, j - 1);
  else return false;
}

int main() {
  int n;
  cin >> n;
  num.resize(n + 1, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%1d", &num[i][j]);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool flag = dfs(n, i);
    if (!flag)  ans.push_back(i + 1);
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1)  cout << " ";
  }
  return 0;
}