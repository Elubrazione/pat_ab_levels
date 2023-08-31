#include <bits/stdc++.h>
using namespace std;
vector<double> ropes;

int main() {
  int n;
  cin >> n;
  ropes.resize(n);
  for (int i = 0; i < n; i++)
    cin >> ropes[i];
  sort(ropes.begin(), ropes.end());
  double cur = ropes[0];
  for (int i = 1; i < n; i++) {
    cur = (cur + ropes[i]) / 2;
  }
  cout << (int)cur;
  return 0;
}