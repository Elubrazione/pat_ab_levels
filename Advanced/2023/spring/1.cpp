#include <bits/stdc++.h>
using namespace std;
set<int> s;

bool isPrime(int n) {
  if (n <= 1) return false;
  int sqr = (int)sqrt(n);
  for (int i = 2; i <= sqr; i++)
    if (n % i == 0) return false;
  return true;
}

int main() {
  int n, turn = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)  s.insert(i);
  while (s.size() != 1) {
    vector<int> temp(1);
    for (auto it = s.begin(); it != s.end(); it++)
      temp.push_back(*(it));
    for (int i = 1; i <= temp.size(); i++) {
      bool flag = false;
      if (!turn && (int)sqrt(i) * (int)sqrt(i) == i)  flag = true;
      else if (turn && isPrime(i)) flag = true;
      if (flag) s.erase(temp[i]);
    }
    turn = !turn;
  }
  cout << *(s.begin());
  return 0;
}