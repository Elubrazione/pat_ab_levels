#include <bits/stdc++.h>
using namespace std;
int n, sum, hs;
vector<int> num;

int main() {
  cin >> n;
  num.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    sum += num[i];
  }
  sort(num.begin(), num.end());
  for (int i = 0; i < n / 2; i++)
    hs += num[i];
  printf("%d %d", n % 2, sum - 2 * hs);
  return 0;
}