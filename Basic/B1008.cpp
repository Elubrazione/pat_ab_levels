#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)  cin >> vec[i];
  reverse(vec.begin(), vec.end());
  reverse(vec.begin(), vec.begin() + m%n);
  reverse(vec.begin() + m%n, vec.end());
  for (int i = 0; i < n; i++) {
    cout << vec[i];
    if (i != n - 1)  cout << " ";
  }
  return 0;
}