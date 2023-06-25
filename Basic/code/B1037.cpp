#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> p(3), a(3), ans(3);
  vector<int> res = {0, 17, 29};
  int cur = 0;
  scanf("%d.%d.%d %d.%d.%d", &p[0], &p[1], &p[2], &a[0], &a[1], &a[2]);
  for (int i = 2; i >= 0; i--) {
    a[i] += cur;
    cur = 0;
    if (i) {
      if (a[i] >= p[i])
        ans[i] = a[i] - p[i];
      else {
        ans[i] = a[i] + res[i] - p[i];
        cur = -1;
      }
    } else {
      ans[i] = a[i] - p[i];
    }
  }
  if (ans[0] < 0) {
    ans[0] += 1;
    ans[1] = 16 - ans[1];
    ans[2] = 29 - ans[2];
  }
  printf("%d.%d.%d", ans[0], ans[1], ans[2]);
  return 0;
}