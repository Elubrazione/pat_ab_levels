#include <bits/stdc++.h>
using namespace std;
stack<int> s1, s2;

int main() {
  string s;
  int n, ele;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "I") {
      cin >> ele;
      s1.push(ele);
    } else {
      int ans = 0;
      if (s2.empty()) {
        while (!s1.empty()) {
          int temp = s1.top();
          s1.pop();
          s2.push(temp);
          ans += 2;
        }
      }
      if (s2.empty()) {
        cout << "ERROR\n";
      } else {
        int temp = s2.top();
        s2.pop();
        ans++;
        printf("%d %d\n", temp, ans);
      }
    }
  }
  return 0;
}