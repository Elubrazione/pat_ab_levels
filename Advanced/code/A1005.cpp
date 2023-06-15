#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> temp = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  vector<string> ans;
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < s.size(); i++)
    sum += s[i] - '0';
  if (!sum) {
    cout << "zero";
    return 0;
  }
  while (sum) {
    ans.push_back(temp[sum%10]);
    sum /= 10;
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
    if (i)  cout << " ";
  }
  return 0;
}