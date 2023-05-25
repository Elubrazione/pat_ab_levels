#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  int sum = 0;
  vector<string> ans, base = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
  cin >> n;
  while (n != "") {
    int len = n.length();
    sum += n[len - 1] - '0';
    n.erase(len - 1, 1);
  }
  while (sum != 0) {
    int cur = sum % 10;
    ans.insert(ans.begin(), base[cur]);
    sum /= 10;
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i != ans.size() - 1)
      cout << ans[i] << " ";
    else  cout << ans[i];
  }
  return 0;
}