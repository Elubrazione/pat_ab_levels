#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string start, end, ans1, ans2;
  for (int i = 0; i < n; i++) {
    string a, t1, t2;
    cin >> a >> t1 >> t2;
    if (!i) {
      start = t1;
      end = t2;
      ans1 = a;
      ans2 = a;
      continue;
    }
    if (t1 < start) {
      start = t1;
      ans1 = a;
    }
    if (t2 > end) {
      end = t2;
      ans2 = a;
    }
  }
  cout << ans1 << " " << ans2;
  return 0;
}