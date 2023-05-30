#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a1, b1, a2, b2, c1, c2;
  for (int i=0; i<n; i++) {
    cin >> a1 >> b1 >> a2 >> b2;
    int s = a1 + a2;
    if (s==b1 && s==b2)  continue;
    if (s == b1)  c2++;
    if (s == b2)  c1++;
  }
  cout << c1 << " " << c2;
  return 0;
}