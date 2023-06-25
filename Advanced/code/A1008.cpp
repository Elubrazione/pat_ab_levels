#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pre = 0, cur, step = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    if (cur > pre)
      step += (cur - pre) * 6;
    else
      step += (pre - cur) * 4;
    step += 5;
    pre = cur;
  }
  cout << step;
  return 0;
}