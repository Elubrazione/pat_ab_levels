#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
vector<int> prime;
vector<bool> p(maxn, false);

void findPrime(int n) {
  for (int i = 2; i < maxn; i++) {
    if (i > n)  break;
    if (!p[i]) {
      prime.push_back(i);
      for (int j = i + i; j < maxn; j += i)
        p[j] = true;
    }
  }
  return;
}
int main() {
  int n, cnt = 0;
  cin >> n;
  findPrime(n);
  for (int i = 0; i < prime.size() - 1; i++) {
    if (prime[i+1] - prime[i] == 2)
      cnt++;
  }
  cout << cnt;
  return 0;
}