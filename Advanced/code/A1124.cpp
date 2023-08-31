#include <bits/stdc++.h>
using namespace std;
vector<string> post;
map<string, bool> mp;

int main() {
  int m, n, s, i = 0, cnt = 0;
  cin >> m >> n >> s;
  string str;
  post.resize(m + 1);
  for (i = 1; i <= m; i++)
    cin >> post[i];
  i = s;
  while (i <= m) {
    if (mp.find(post[i]) == mp.end()) {
      cout << post[i] << endl;
      mp[post[i]] = true;
      cnt++;
      i += n;
    } else {
      i++;
    }
  }
  if (!cnt) cout << "Keep going...";
  return 0;
}