// 暴力求解，17/30，AC做法是用快乐模拟
#include <bits/stdc++.h>
using namespace std;

vector<int> now;
vector<int> num, k(1e5 + 1, INT_MIN);
vector<vector<int>> ans(1);

int main() {
  int n, m, mx = INT_MIN;
  cin >> n >> m;
  num.resize(n);
  for (int i = 0; i < n; i++) cin >> num[i];

  int i = 0, cur = 0;
  while (i < n + m) {
    if (now.size() < m && i < n) {
      now.push_back(num[i++]);
      continue;
    }
    sort(now.begin(), now.end());
    int p = 0;
    while (p < now.size() && now[p] <= k[cur])  p++;
    if (p == now.size()) {
      ans.push_back(vector<int>());
      cur++;
      p = 0;
    }
    ans[cur].push_back(now[p]);
    k[cur] = now[p];
    if (i < n) now[p] = num[i];
    else  now.erase(now.begin() + p);
    i++;
  }
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      if (j) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}