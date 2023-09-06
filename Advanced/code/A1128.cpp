// 任意两个皇后都要不在同⼀⾏或者同⼀列，且不在斜对⻆线上
#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, num;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> num;
    vector<int> v(num);
    bool result = true;
    for (int j = 0; j < num; j++) {
      cin >> v[j];
      for (int t = 0; t < j; t++) {
        if (v[j] == v[t] || abs(v[j]-v[t]) == abs(j-t)) {
          result = false;
          break;
        }
      }
    }
    cout << (result == true ? "YES\n" : "NO\n");
  }
  return 0;
}