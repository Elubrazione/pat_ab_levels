#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<double> a(1001, 0), b(1001, 0), s(2001, 0);
  int num, exp;
  double coe;
  cin >> num;
  while (num--) {
    cin >> exp >> coe;
    a[exp] = coe;
  }
  cin >> num;
  while (num--) {
    cin >> exp >> coe;
    b[exp] = coe;
  }
  for (int i = 0; i < 1001; i++)
    for (int j = 0; j < 1001; j++)
      s[i+j] += (double) a[i] * b[j];
  int cnt = 0;
  for (int i = 0; i < 2001; i++)
    if (s[i] != 0.0)
      cnt++;
  cout << cnt;
  for (int i = 2000; i >= 0; i--)
    if (s[i] != 0.0)
      printf(" %d %.1f", i, s[i]);
  return 0;
}