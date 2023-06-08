#include <bits/stdc++.h>
using namespace std;

int lessEqualTool(string &a, string &c, int n) {
  int pos = 0;
  auto f = a.find('.');

  if (f != string::npos) {
    while (a[f+1] == '0') {
      a.erase(f + 1, 1);
      pos--;
    }
    if (a.size() == f + 1)  pos = 0;
    if (a.size() - f > n) {
      c += a.substr(f + 1, n);
    } else {
      c += a.substr(f + 1, a.size() - f);
      int k = n - (a.size() - f) + 1;
      while (k--)
        c.push_back('0');
    }
  } else {
    while (n--)
      c.push_back('0');
  }
  return pos;
}

void greaterTool(string &a, string &c, int n) {
  while(n--) {
    if (a.size() > 0) {
      if (a[0] == '.') {
        n++;
        a.erase(0, 1);
        continue;
      }
      c.push_back(a[0]);
      a.erase(0, 1);
    } else {
      c.push_back('0');
    }
  }
  return;
}

int getNumber(string a) {
  auto f = a.find('.');
  if (f != string::npos)
    return f;
  else  return a.size();
}

int main() {
  int n;
  string a, b, c, d;
  c = d = "0.";
  cin >> n >> a >> b;

  while (a.size() > 1 && a[0] == '0' && a[1] != '.')
    a.erase(0, 1);
  while (b.size() > 1 && b[0] == '0' && b[1] != '.')
    b.erase(0, 1);

  int n1 = getNumber(a), n2 = getNumber(b);

  if (a[0] == '0')  n1 = lessEqualTool(a, c, n);
  else  greaterTool(a, c, n);
  if (b[0] == '0')  n2 = lessEqualTool(b, d, n);
  else  greaterTool(b, d, n);

  if (c == d) {
    cout << "YES ";
    cout << c << "*10^" << n1;
  }
  else {
    cout << "NO ";
    cout << c << "*10^" << n1 << " ";
    cout << d << "*10^" << n2;
  }
  return 0;
}