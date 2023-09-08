#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
  int len = s.size();
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - 1 - i])
      return false;
  }
  return true;
}

string addTwo(string &pre, string &origin) {
  string res = "";
  int ad = 0;
  for (int i = pre.size() - 1; i >= 0; i--) {
    int sum = pre[i] - '0' + origin[i] - '0' + ad;
    if (sum >= 10) {
      sum -= 10;
      ad = 1;
    } else {
      ad = 0;
    }
    res.push_back(to_string(sum)[0]);
  }
  if (ad == 1)  res.push_back('1');
  reverse(res.begin(), res.end());
  return res;
}


int main() {
  string origin;
  cin >> origin;
  string pre = origin;
  bool flag = false;
  for (int i = 0; i < 10; i++) {
    if (isPalindrome(origin)) {
      printf("%s is a palindromic number.\n", origin.c_str());
      flag = true;
      break;
    } else {
      reverse(origin.begin(), origin.end());
      string res = addTwo(pre, origin);
      printf("%s + %s = %s\n", pre.c_str(), origin.c_str(), res.c_str());
      origin = pre = res;
    }
  }
  if (!flag)  printf("Not found in 10 iterations.");
  return 0;
}