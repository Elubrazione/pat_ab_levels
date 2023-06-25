#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d;
  cin >> a >> b >> d;
  int c = a + b;
  vector<int> vec;
  do {
    vec.push_back(c%d);
    c /= d;
  } while (c);
  for (int i = vec.size() - 1; i >= 0; i--)
    cout << vec[i];
  return 0;
}