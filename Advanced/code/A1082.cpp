#include <bits/stdc++.h>
using namespace std;

// 最后一个测试点没过
int main() {
  string s;
  cin >> s;
  if (s == "0") {
    cout << "ling";
    return 0;
  }
  vector<string> ans;
  vector<string> tpl1 = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  vector<string> tpl2 = {"", "Wan", "Yi"}, tpl3 = {"", "Shi", "Bai", "Qian"};
  if (s[0] == '-') {
    ans.push_back("Fu");
    s = s.substr(1, s.size() - 1);
  }
  reverse(s.begin(), s.end());
  for (int i = s.size() - 1; i >= 0; i--) {
    int cur = s[i] - '0', res = i % 4, div = i / 4;
    if (cur)
      ans.push_back(tpl1[cur]);
    if (res && cur)
      ans.push_back(tpl3[res]);
    if (!res && div) {
      ans.push_back(tpl2[div]);
      string nxt = s.substr(i - 4, 4);
      reverse(nxt.begin(), nxt.end());
      // cout << nxt << endl;
      if (nxt > "0000" && nxt < "1000")
        ans.push_back("ling");
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1)
      cout << " ";
  }
  return 0;
}