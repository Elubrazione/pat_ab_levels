#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  vector<string> vec;
  while (cin >> s)  vec.push_back(s);
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i != vec.size() - 1)  cout << " ";
  }
  return 0;
}