#include <bits/stdc++.h>
using namespace std;
vector<int> res;

void decimalToB(int n, int b) {
  do {
    res.push_back(n % b);
    n /= b;
  } while (n);
  return;
}

bool isPalinfromic() {
  for (int i = 0; i < res.size() / 2; i++) {
    if (res[i] != res[res.size()-1-i])
      return false;
  }
  return true;
}

int main() {
  int n, b;
  cin >> n >> b;
  decimalToB(n, b);
  bool flag = isPalinfromic();
  if (flag)  cout << "Yes" << endl;
  else  cout << "No" << endl;
  for (int i = res.size() - 1; i >= 0; i--) {
    cout << res[i];
    if (i)  cout << " ";
  }
  return 0;
}