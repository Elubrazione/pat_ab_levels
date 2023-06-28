#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(3), b(3), p(3);
  vector<int> vec = {0, 17, 29};
  int cur = 0;
  scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
  for (int i = 2; i >= 0; i--) {
    p[i] = a[i] + b[i] + cur;
    cur = 0;
    if (p[i] >= vec[i]) {
      cur = 1;
      p[i] -= vec[i];
    }
  }
  printf("%d.%d.%d", p[0], p[1], p[2]);
  return 0;
}