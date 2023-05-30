#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
  double a4 = 0.0;
  int n = 0, fg = 1, cnt = 0, count = 0;
  cin >> n;
  while(n--) {
    int cur;
    cin >> cur;
    if (!(cur%10)) {
      a1 += cur;
      continue;
    }
    if (cur%5 == 1) {
      a2 += fg * cur;
      fg *= -1;
      count++;
      continue;
    }
    if (cur%5 == 2) {
      a3++;
      continue;
    }
    if (cur%5 == 3) {
      a4 += cur;
      cnt++;
      continue;
    }
    if (cur%5 == 4) {
      a5 = max(a5, cur);
      continue;
    }
  }
  if (cnt)  a4 = (double)a4*1.0 / cnt;
  if (a1)  cout << a1 << " ";
  else  cout << "N ";
  if (count)  cout << a2 << " ";
  else  cout << "N ";
  if (a3)  cout << a3 << " ";
  else  cout << "N ";
  if (a4)  printf("%.1f ", a4);
  else  cout << "N ";
  if (a5)  cout << a5;
  else  cout << "N";
  return 0;
}