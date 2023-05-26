# include <bits/stdc++.h>
using namespace std;
int main() {
  int num, i = 2;
  cin >> num;
  vector<int> res(3, 0);
  while (num) {
    res[i] = num % 10;
    num /= 10;
    i--;
  }
  vector<string> base = {"B", "S", "123456789"};
  for (int i = 0; i < 3; i++) {
    if (i != 2)
      for (int j = 0; j < res[i]; j++)
        cout << base[i];
    else  cout << base[2].substr(0, res[i]);
  }
  return 0;
}