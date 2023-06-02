# include <bits/stdc++.h>
using namespace std;
int main() {
  int a, da, b, db;
  cin >> a >> da >> b >> db;
  int ans = 0;
  int cnt = 1;
  while(a) {
    int res = a % 10;
    if (res == da) {
      ans += cnt * res;
      cnt *= 10;
    }
    a /= 10;
  }
  cnt = 1;
  while (b) {
    int res = b % 10;
    if (res == db) {
      ans += cnt * res;
      cnt *= 10;
    }
    b /= 10;
  }
  cout << ans;
  return 0;
}