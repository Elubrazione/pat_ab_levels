#include <bits/stdc++.h>
using namespace std;
string n1, n2;
long long tag, radix;

int char2Number(char c) {
  int res = 0;
  if (c >= '0' && c <= '9')
    res = c - '0';
  else  res = c  - 'a' + 10;
  return res;
}

long long decimalTo10(string s, long long r) {
  long long  product = 1, sum = 0;
  for (int i = s.size()-1; i >= 0; i--) {
    sum += char2Number(s[i]) * product;
    product *= r;
  }
  return sum;
}

int main() {
  cin >> n1 >> n2 >> tag >> radix;
  if (tag == 2) {
    string temp = n2;
    n2 = n1;
    n1 = temp;
  }
  long long n1_10 = decimalTo10(n1, radix);

  // find min decimal
  char maxs = '0';
  for (int i = 0; i < n2.size(); i++) {
    if (n2[i] > maxs)
      maxs = n2[i];
  }
  int maxd = char2Number(maxs);

  // search for equation
  long long low = maxd + 1, high = max((long long)maxd, n1_10) + 1;
  while (low <= high) {
    long long mid = (low + high) >> 1;
    long long n2_10 = decimalTo10(n2, mid);
    if (n2_10 > n1_10 || n2_10 < 0)
      high = mid - 1;
    else if (n2_10 == n1_10) {
      cout << mid;
      return 0;
    }
    else  low = mid + 1;
  }
  cout << "Impossible";
  return 0;
}