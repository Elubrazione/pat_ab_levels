#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a, b, c;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    long long sum = a + b;
    bool flag = false;
    if (a > 0 && b > 0 && sum < 0)  flag = true;
    else if (a < 0 && b < 0 && sum >= 0)  flag = false;
    else if (sum > c)  flag = true;
    else  flag = false;
    if (flag)  printf("Case #%d: true", i + 1);
    else  printf("Case #%d: false", i + 1);
    if (i != n - 1)  cout << endl;
  }
  return 0;
}