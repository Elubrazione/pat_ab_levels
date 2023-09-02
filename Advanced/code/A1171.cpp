#include <bits/stdc++.h>
using namespace std;
vector<int> num, remain, ans;
priority_queue<int, vector<int>, greater<int>> now;

int main() {
  int n, m, cnt = 0, i, pre = INT_MIN;
  cin >> n >> m;
  num.resize(n);
  for (i = 0; i < n; i++) cin >> num[i];
  i = 0;
  while (now.size() < m)  now.push(num[i++]);
  while (cnt < n) {
    if (now.empty()) {
      for (auto item: remain)
        now.push(item);
      for (int j = 0; j < ans.size(); j++) {
        cout << ans[j];
        if (j != ans.size() - 1)  cout << " ";
      }
      cnt += ans.size();
      cout << endl;
      ans.clear();
      remain.clear();
    } else {
      int cur = now.top();
      now.pop();
      ans.push_back(cur);
      pre = cur;
      if (i < n) {
        if (num[i] <= pre)
          remain.push_back(num[i++]);
        else  now.push(num[i++]);
      }
    }
  }
  return 0;
}