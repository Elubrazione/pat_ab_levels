#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
vector<bool> p(maxn, false);

void findPrime() {
  p[0] = p[1] = true;
  for (int i = 2; i <= maxn; i++) {
    if (!p[i]) {
      for (int j = i + i; j <= maxn; j += i)
        p[j] = true;
    }
  }
  return;
}

vector<int> decimalFrom_10(int s, int radix) {
  vector<int> trans_n;
  do {
    trans_n.push_back(s % radix);
    s /= radix;
  } while (s);
  return trans_n;
}

int decimalTo_10(vector<int> str, int radix) {
  int product = 1, sum = 0;
  for (int i = str.size() - 1; i >= 0; i--) {
    sum += product * str[i];
    product *= radix;
  }
  return sum;
}

int main() {
  int r, n;
  findPrime();
  while (1) {
    cin >> n;
    if (n < 0)  break;
    cin >> r;
    vector<int> temp = decimalFrom_10(n, r);
    int n_ = decimalTo_10(temp, r);
    if (!p[n] && !p[n_])  cout << "Yes" << endl;
    else  cout << "No" << endl;
  }
  return 0;
}