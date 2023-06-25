#include <bits/stdc++.h>
using namespace std;

// 测试点2和5不过
int main() {
  int n, start = 0, end = 0, mx;
  bool flag = true;
  cin >> n;
  vector<int> dp(n, 0), vec(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (vec[i] >= 0)  flag = false;
    if (!i) {
      dp[i] = vec[i];
      mx = dp[i];
      continue;
    }
    if (dp[i-1] + vec[i] < vec[i]) {
      dp[i] = vec[i];
      if (dp[i] > mx) {
        mx = dp[i];
        start = i;
        end = i;
      }
    } else {
      dp[i] = dp[i-1] + vec[i];
      if (dp[i] > mx) {
        mx = dp[i];
        end = i;
      }
    }
  }
  if (flag)
    printf("0 %d %d", vec[0], vec[vec.size()-1]);
  else
    printf("%d %d %d", dp[end], vec[start], vec[end]);
  return 0;
}