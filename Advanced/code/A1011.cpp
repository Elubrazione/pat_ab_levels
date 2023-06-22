#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<char> hash = {'W', 'T', 'L'};
  vector<char> ans;
  double pro = 1.0, cur;
  for (int i = 0; i < 3; i++) {
    double mx = -1;
    int id = 0;
    for (int j = 0; j < 3; j++) {
      cin >> cur;
      if (cur > mx) {
        mx = cur;
        id = j;
      }
    }
    pro *= mx;
    ans.push_back(hash[id]);
  }
  // The winner's odd would be the product of the three odds times 65%.
  pro = (pro * 0.65 - 1) * 2;
  printf("%c %c %c %.2f", ans[0], ans[1], ans[2], pro);
  return 0;
}