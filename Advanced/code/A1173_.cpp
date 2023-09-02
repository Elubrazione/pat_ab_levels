// 动态规划 空间超了
#include <bits/stdc++.h>
using namespace std;
vector<int> price;
vector<vector<int>> dp;

int main() {
  int n, m;
  cin >> n >> m;
  price.resize(n + 1);
  dp.resize(n + 1, vector<int>(n + 1, -1));
  for (int i = 1; i <= n; i++) {
    cin >> price[i];
    dp[i][i] = m - price[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= j) continue;
      if (price[j] <= dp[i][j-1]) {
        dp[i][j] = dp[i][j-1] - price[j];
      } else {
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (dp[i][j] >= 0)  ans++;
  cout << ans;
  return 0;
}