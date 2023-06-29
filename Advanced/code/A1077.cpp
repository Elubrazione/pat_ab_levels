#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, mx = INT_MAX;
  cin >> n;
  vector<string> str(n);

  // 后面要使用getline来读取一整行带空格的字符串
  // 因此这里要使用getchar来跳过第一行个数n后面的换行符
  char c = getchar();

  for (int i = 0; i < n; i++) {
    getline(cin, str[i]);
    int l = str[i].size();
    mx = min(mx, l);
    reverse(str[i].begin(), str[i].end());
  }
  int maxLen = 0;
  for (int i = 0; i < mx; i++) {
    bool flag = true;
    for (int j = 1; j < n; j++) {
      if (str[j][i] != str[0][i]) {
        flag = false;
        break;
      }
    }
    if (flag)  maxLen++;
    else  break;
  }
  if (!maxLen)  cout << "nai";
  else {
    string s = str[0].substr(0, maxLen);
    reverse(s.begin(), s.end());
    cout << s;
  }
  return 0;
}