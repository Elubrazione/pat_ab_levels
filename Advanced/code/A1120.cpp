#include <bits/stdc++.h>
using namespace std;
vector<bool> vis(40, false);
vector<int> ans;

int calFriendId(int s) {
  int sum = 0;
  do {
    sum += s % 10;
    s /= 10;
  } while (s);
  return sum;
}

int main() {
  int n, cur;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    int id = calFriendId(cur);
    vis[id] = true;
  }
  for (int i = 0; i < vis.size(); i++)
    if (vis[i])
      ans.push_back(i);
  cout << ans.size() << endl << ans[0];
  for (int i = 1; i < ans.size(); i++)
    cout << " " << ans[i];
  return 0;
}