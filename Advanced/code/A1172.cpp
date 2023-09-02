#include <bits/stdc++.h>
using namespace std;
vector<int> num, l, r;

int main() {
  int n, sum = 0;
  cin >> n;
  num.resize(n), l.resize(n, 2), r.resize(n, 2);
  for (int i = 0; i < n; i++)  cin >> num[i];
  for (int i = 1; i < n; i++) {
    if (num[i] > num[i-1])  l[i] = l[i-1] + 1;
    else if (num[i] == num[i-1])  l[i] = l[i-1];
  }
  for (int i = n - 2; i >= 0; i--) {
    if (num[i] > num [i+1]) r[i] = r[i+1] + 1;
    else if (num[i] == num[i+1])  r[i] = r[i+1];
  }
  for (int i = 0; i < n; i++)
    sum += max(l[i], r[i]) * 100;
  cout << sum;
  return 0;
}