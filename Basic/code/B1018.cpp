#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v = 0;
  cin >> n;
  vector<int> a(3, 0), b(3, 0);
  while (n--) {
    char c, d;
    cin >> c >> d;
    if (abs(c-d) == 8) {
      if (c - d > 0)  a[2]++;
      else  b[2]++;
    } else if (abs(c-d) == 7) {
      if (c - d > 0)  b[1]++;
      else  a[1]++;
    } else if (abs(c-d) == 1) {
      if (c - d > 0)  b[0]++;
      else  a[0]++;
    } else {
      v++;
    }
  }
  int win1 = 0, win2 = 0, m1 = 0, m2 = 0;
  for (int i=0; i<3; i++) {
    if (a[i] > a[m1])  m1 = i;
    if (b[i] > b[m2])  m2 = i;
    win1 += a[i];
    win2 += b[i];
  }
  char e1 = m1? (m1==1? 'C': 'J'): 'B';
  char e2 = m2? (m2==1? 'C': 'J'): 'B';
  cout << win1 << " " << v << " " << win2 << endl;
  cout << win2 << " " << v << " " << win1 << endl;
  cout << e1 << " " << e2;
  return 0;
}