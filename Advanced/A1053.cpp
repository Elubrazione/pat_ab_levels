#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> temp;
vector<vector<int>> ans;

struct TreeNode {
  int weight;
  vector<int> child;
} treeNode[110];

void dfs(int index, int sum) {
  if (sum == s && !treeNode[index].child.size()) {
    ans.push_back(temp);
    return;
  }
  if (index >= n || !treeNode[index].child.size())  return;
  for (int i = 0; i < treeNode[index].child.size(); i++) {
    int curW = treeNode[treeNode[index].child[i]].weight;
    int curSum = sum + curW;
    if (curSum <= s) {
      temp.push_back(curW);
      dfs(treeNode[index].child[i], curSum);
      temp.pop_back();
    }
  }
  return;
}

int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++)
    cin >> treeNode[i].weight;
  for (int i = 0; i < m; i++) {
    int cur, num, k;
    scanf("%d %d", &cur, &num);
    for (int j = 0; j < num; j++) {
      scanf("%d", &k);
      treeNode[cur].child.push_back(k);
    }
  }
  temp.push_back(treeNode[0].weight);
  dfs(0, treeNode[0].weight);
  sort(ans.begin(), ans.end(), [&](vector<int> a, vector<int> b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
      if (a[i] == b[i])  continue;
      else  return a[i] > b[i];
    }
    // 如果都相等，返回false（测试点5）
    return false;
  });
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j];
      if (j != ans[i].size() - 1)
        cout << " ";
    }
    if (i != ans.size() - 1)
      cout << endl;
  }
  return 0;
}