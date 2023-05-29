#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, fg = 1, fst = 1;
  while (cin >> a >> b) {
    if (!b) {
      if (fst) {
        cout << 0 << " " << 0;
        break;
      }
      continue;
    }
    else {
      fst = 0;
      a *= b;
      if (fg) {
        cout << a << " " << b - 1;
        fg = 0;
      }
      else  cout << " " << a << " " << b - 1;
    }
  }
  return 0;
}