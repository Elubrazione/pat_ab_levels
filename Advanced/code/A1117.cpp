#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

int main() {
  int n, i;
  cin >> n;
  vec.resize(n);
  for (int i = 0; i < n; i++)  cin >> vec[i];
  sort(vec.begin(), vec.end(), greater<int>());
  for (i = 0; i < n; i++)
    if (i + 1 > vec[i])  break;
  cout << vec[i-1] - 1;
  return 0;
}