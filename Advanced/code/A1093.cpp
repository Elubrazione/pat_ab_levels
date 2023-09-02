#include <bits/stdc++.h>
using namespace std;
const int d = 1000000007;
vector<int> leftNum;

int main() {
  string str;
  cin >> str;
  int len = str.size(), ans = 0, rightNum = 0;
  leftNum.resize(len, 0);

  for (int i = 0; i < len; i++) {
    if (i > 0)  leftNum[i] = leftNum[i-1];
    if (str[i] == 'P')  leftNum[i]++;
  }
  for (int i = len - 1; i >= 0; i--) {
    if (str[i] == 'T')  rightNum++;
    else if (str[i] == 'A')
      ans = (ans + rightNum * leftNum[i]) % d;
  }
  cout << ans;
  return 0;
}