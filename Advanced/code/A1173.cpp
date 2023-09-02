#include <bits/stdc++.h>
using namespace std;
vector<int> price;
int ans = 0, n, m;

void dfs(int i, int j, int remain) {
  if (i >= n || j >= n) return;
  if (price[j] <= remain) {
    // cout << i << " " << j << endl;
    ans++;
    if (j != n - 1) {
      dfs(i, j + 1, remain - price[j]);
    } else {
      dfs(i + 1, i + 1, m);
    }
  } else {
    dfs(i + 1, i + 1, m);
  }
}

int main() {
  cin >> n >> m;
  price.resize(n);
  for (int i = 0; i < n; i++) cin >> price[i];
  dfs(0, 0, m);
  cout << ans;
  return 0;
}