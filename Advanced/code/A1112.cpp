#include <bits/stdc++.h>
using namespace std;
int n;
string ori, alt;
map<char, bool> mp;
map<char, bool> prt;

int main() {
  cin >> n >> ori;
  int i = 0;
  while (i < ori.size()) {
    int k = i + 1;
    while (k < ori.size() && ori[i] == ori[k])  k++;
    if (k - i >= n) {
      if ((k - i) % n == 0) {
        mp[ori[i]] = true;
        prt[ori[i]] = true;
      } else {
        mp[ori[i]] = false;
        prt[ori[i]] = false;
      }
      i = k;
    } else {
      mp[ori[i]] = false;
      prt[ori[i]] = false;
      i++;
    }
  }
  i = 0;
  while (i < ori.size()) {
    if (mp[ori[i]] == false) {
      alt.push_back(ori[i]);
      i++;
    } else {
      int k = i + 1;
      while (k < ori.size() && ori[i] == ori[k])  k++;
      int cur = k - i;
      while (cur > 0) {
        alt.push_back(ori[i]);
        cur -= n;
      }
      if (prt[ori[i]] == true) {
        cout << ori[i];
        prt[ori[i]] = false;
      }
      i = k;
    }
  }
  cout << endl << alt;
  return 0;
}