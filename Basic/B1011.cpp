#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long a, b, c;
    cin >> a >> b >> c;
    string fg = a+b>c? "true": "false";
    cout << "Case #" << i+1 << ": " << fg;
    if (i != n - 1)  cout << endl;
  }
  return 0;
}