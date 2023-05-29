#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin>> a>> b;
  int sum = a + b;
  int fg = a+b>=0? 1: 0;
  sum = abs(sum);
  string str = to_string(sum);
  if (!fg)  cout << "-";
  vector<string> ans;
  for (int i = str.size()-3; i >= 0; i-=3) {
    ans.push_back(str.substr(i, 3));
    if (i)  ans.push_back(",");
  }
  ans.push_back(str.substr(0, str.size()%3));
  reverse(ans.begin(), ans.end());
  for (const auto& it: ans)  cout << it;
  return 0;
}