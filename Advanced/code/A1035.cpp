#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  if (n == 1) {
    cout << "There is 1 account and no account is modified";
    return 0;
  }
  vector<string> ans1, ans2;
  for (int i = 0; i < n; i++) {
    string user, pwd;
    cin >> user >> pwd;
    bool flag = false;
    for (int j = 0; j < pwd.size(); j++) {
      switch (pwd[j]) {
        case '1':
          pwd[j] = '@';
          flag = true;
          break;
        case '0':
          pwd[j] = '%';
          flag = true;
          break;
        case 'l':
          pwd[j] = 'L';
          flag = true;
          break;
        case 'O':
          pwd[j] = 'o';
          flag = true;
          break;
      }
    }
    if (flag) {
      ans1.push_back(user);
      ans2.push_back(pwd);
      cnt++;
    }
  }
  if (!cnt)
    printf("There are %d accounts and no account is modified", n);
  else {
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
      cout << ans1[i] << " " << ans2[i];
      if (i != cnt - 1)
        cout << endl;
    }
  }
  return 0;
}