# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> res, ans;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int cur;
    cin >> cur;
    res.push_back(cur);
    while (cur) {
      if (!(cur % 2))  cur /= 2;
      else  cur = (3 * cur + 1) / 2;
      if (mp[cur])  break;
      mp[cur]++;
    }
  }
  sort(res.begin(), res.end(), [&](int a, int b) {
    return a > b;
  });
  for (int i = 0; i < n; i++) {
    if (mp[res[i]])  continue;
    ans.push_back(res[i]);
  }
  for (int i = 0; i < ans.size() ; i++) {
    if (i != ans.size() - 1)  cout << ans[i] << " ";
    else  cout << ans[i];
  }
  return 0;
}