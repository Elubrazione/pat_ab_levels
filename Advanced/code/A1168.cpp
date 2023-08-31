#include <bits/stdc++.h>
using namespace std;

bool isPrime(int number) {
  if (number <= 1) return false;
  int sqr = (int)sqrt(number), i;
  for (i = 2; i <= sqr; i++)
    if (number % i == 0) return false;
  return true;
}

int main() {
  bool flag = true;
  string n;
  cin >> n;
  for (int i = 8; i > 0; i--) {
    string str = n.substr(8 - i, i);
    int cur = stoi(str);
    bool fg = isPrime(cur);
    printf("%s %s\n", str.c_str(), fg? "Yes": "No");
    if (!fg) flag = false;
  }
  if (flag) cout << "All Prime!";
  return 0;
}