#include <bits/stdc++.h>
using namespace std;
vector<int> num, l, r;
set<int> ans;

int main() {
  int n;
  cin >> n;
  num.resize(n);
  l.resize(n);
  r.resize(n);
  l[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    l[i] = max(l[i-1], num[i-1]);
  }
  r[n-1] = INT_MAX;
  for (int i = n - 2; i >= 0; i--)
    r[i] = min(r[i+1], num[i+1]);
  for (int i = 0; i < n; i++)
    if (l[i] < num[i] && r[i] > num[i])
      ans.insert(num[i]);
  cout << ans.size() << endl;
  for (auto it = ans.begin(); it != ans.end(); it++) {
    if (it == ans.begin())  cout << *(it);
    else  cout << " " << *(it);
  }
  cout << endl;
  return 0;
}