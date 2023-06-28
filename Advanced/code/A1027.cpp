#include <bits/stdc++.h>
using namespace std;
vector<char> vec(13, '0');

string decimalTo13(int n) {
  string str = "00";
  int i = 0;
  do {
    int cur = n % 13;
    if (cur <= 9)  str[1-i] = cur + '0';
    else  str[1-i] = vec[cur];
    n /= 13;
    i++;
  } while (n);
  return str;
}

int main() {
  vec[10] = 'A';
  vec[11] = 'B';
  vec[12] = 'C';
  int r, g, b;
  cin >> r >> g >> b;
  string red = decimalTo13(r);
  string green = decimalTo13(g);
  string blue = decimalTo13(b);
  cout << "#" << red << green << blue;
  return 0;
}