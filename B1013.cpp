# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
vector<int> prime;
vector<bool> p(maxn, false);

void findPrime(int n) {
  for (int i = 2; i < maxn; i++) {
    if (!p[i]) {
      prime.push_back(i);
      if (prime.size() == n)  break;
      for (int j = i + i; j < maxn; j += i)
        p[j] = true;
    }
  }
  return;
}

int main() {
  int m, n, cnt = 0;
  cin >> m >> n;
  findPrime(n);
  for (int i = m; i <= n; i++) {
    cout << prime[i-1];
    cnt++;
    if (cnt % 10 != 0 && i < n)  cout << " ";
    else  cout << endl;
  }
  return 0;
}