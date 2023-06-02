#include <bits/stdc++.h>
using namespace std;
int n, m, d = -1;
vector<int> ans;
vector<vector<int>> node;

void dfs(int index, int depth) {
  if (!node[index].size()) {
    ans[depth]++;
    d = max(d, depth);
  }
  for(int i = 0; i < node[index].size(); i++)
    dfs(node[index][i], depth + 1);
  return;
}

int main() {
  cin >> n >> m;
  node.resize(n + 1);
  ans.resize(n, 0);
  for (int i = 0; i < m; i++) {
    int cur, num, k;
    scanf("%d %d", &cur, &num);
    for (int j = 0; j < num; j++) {
      scanf("%d", &k);
      node[cur].push_back(k);
    }
  }
  dfs(1, 0);
  for (int i = 0; i <= d; i++) {
    cout << ans[i];
    if (i != d)  cout << " ";
  }
}