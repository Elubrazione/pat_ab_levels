#include <bits/stdc++.h>
using namespace std;
bool isCorrect(string s) {
  int cur = 0, fg = 0;
  vector<int> cnt(3, 0);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != 'A' && s[i] != 'T' && s[i] != 'P')  return false;
    if (s[i] == 'A')  cnt[cur]++;
    else if (s[i] == 'T')  {
      if (!cnt[0] && !fg)  return false;
      else  cur++;
    } else {
      cur++;
      fg = 1;
    }
    if (cur > 2)  return false;
  }
  return (cnt[0] * cnt[1] == cnt[2]) && cnt[1] && cur == 2? true: false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (isCorrect(s))  cout << "YES";
    else  cout << "NO";
    if (i != n - 1)  cout << endl;
  }
  return 0;
}