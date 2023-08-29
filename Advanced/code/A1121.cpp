#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> companion(maxn, -1), ans, info;
vector<bool> guest(maxn, false);

// 1、最后单身狗的人数为0的时候，需要特殊处理一下
// 2、每个人的身份编号都5位数，需要输出00000,00001这样的编号
// 3、编号可能会0，对于存储配偶的数据结构，不能初始化为0

int main() {
  int n, m, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    companion[a] = b;
    companion[b] = a;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a;
    guest[a] = true;
    info.push_back(a);
  }
  for (auto p: info) {
    if (companion[p] == -1) {
      ans.push_back(p);
    } else {
      if (!guest[companion[p]])
        ans.push_back(p);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size();
  if (ans.size())  printf("\n%05d", ans[0]);
  for (int i = 1; i < ans.size(); i++)
    printf(" %05d", ans[i]);
  return 0;
}