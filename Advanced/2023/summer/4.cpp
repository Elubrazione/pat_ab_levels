#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int cur, vector<int>& tv, vector<int>& res, set<pair<int,int>>& cap) {
  if (cur == 10 || cur > n) {
    res = min(res, tv);
    return;
  }
  for (int i = 0; i < 10; ++i) {
    if (cur==1&&i==0) continue;
    if (cap.count({cur, i})) {
      cap.erase({cur, i});
      tv[cur] = i;
      dfs(cur+1, tv, res, cap);
      cap.emplace(cur, i);
    }
    if (cap.count({i, cur})) {
      cap.erase({i, cur});
      tv[cur] = i;
      dfs(cur+1, tv, res, cap);
      cap.emplace(i, cur);
    }
  }
}
int main() {
  cin >> n;
  set<pair<int,int>> cap;
  vector<int> v(n+1);//storage: index >= 10
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a >= 10) {
      v[a] = b;
    } else if (b >= 10) {
      v[b] = a;
    } else {
      if (cap.count({a, b})) cap.emplace(b, a);
      else cap.emplace(a, b);
    }
  }
  vector<int> res(10, 0x3f3f3f3f);
  vector<int> tv(10, 0x3f3f3f3f);//temp vector
  dfs(1, tv, res, cap);
  for (int i = 1; i < 10 && i <= n; ++i)
    cout<<res[i];
  for (int i = 10; i <= n; ++i) cout<<v[i];
  return 0;
}