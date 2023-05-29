#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<char> mp = {'S', 'H', 'C', 'D', 'J'};
  vector<int> order(54, 0), a(54, 0);
  iota(a.begin(), a.end(), 1);
  cin >> n;
  for (int i=0; i<54; i++)  cin >> order[i];
  while (n--) {
    vector<int> b = a;
    for (int i=0; i<54; i++) {
      a[order[i]-1] = b[i];
    }
  }
  for (int i=0; i<54; i++) {
    cout << mp[(a[i]-1)/13] << a[i]-((a[i]-1)/13)*13;
    if (i != 53)  cout << " ";
  }
  return 0;
}