#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> ans = {-1, -1};
vector<int> level;
vector<vector<int>> node;

void dfs(int index, int depth) {
  level[depth]++;
  if (level[depth] > ans.first) {
    ans.first = level[depth];
    ans.second = depth;
  }
  if (!node[index].size())  return;
  for (int i = 0; i < node[index].size(); i++)
    dfs(node[index][i], depth + 1);
  return;
}

int main() {
  cin >> n >> m;
  node.resize(n + 1);
  level.resize(m + 1);
  vector<bool> isRoot(n + 1, true);
  isRoot[0] = false;
  for (int i = 0;i < m; i++) {
    int num, k, cur;
    scanf("%d %d", &num, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &cur);
      node[num].push_back(cur);
      isRoot[cur] = false;
    }
  }
  int i;
  for (i = 0; i <= n; i++)
    if (isRoot[i])  break;
  dfs(i, 1);
  cout << ans.first << " " << ans.second;
  return 0;
}