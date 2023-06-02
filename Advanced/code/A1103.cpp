#include <bits/stdc++.h>
using namespace std;
int n, k, p, maxSum = -1;
vector<int> A;
vector<int> ans, temp;

void dfs(int index, int nowK, int sum, int sumFac) {
  if (nowK == k && sum == n) {
    if (sumFac > maxSum) {
      ans = temp;
      maxSum = sumFac;
    }
    return;
  }
  if (nowK > k || sum > n || index < 0)  return;
  if (sum + pow(A[index], p) <= n) {
    temp.push_back(A[index]);
    dfs(index, nowK + 1, sum + pow(A[index], p), sumFac + A[index]);
    temp.pop_back();
  }
  dfs(index - 1, nowK, sum, sumFac);
}
int main() {
  cin >> n >> k >> p;
  A.resize(sqrt(n));
  iota(A.begin(), A.end(), 1);
  dfs(A.size() - 1, 0, 0, 0);
  if (maxSum == -1) {
    cout << "Impossible";
    return 0;
  }
  cout << n << " = ";
  for (int i = 0; i < k; i++) {
    printf("%d^%d", ans[i], p);
    if (i != k-1)  cout << " + ";
  }
  return 0;
}