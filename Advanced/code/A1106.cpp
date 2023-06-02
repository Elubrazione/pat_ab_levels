#include <bits/stdc++.h>
using namespace std;
int n;
double p, r;
pair<double, int> ans = {INT_MAX, 0};
vector<vector<int>> node;

void dfs(int index, int depth) {
  if (!node[index].size()) {
    double price = pow(1+r, depth) * p;
    if (price < ans.first) {
      ans.first = price;
      ans.second = 1;
    } else if (price == ans.first) {
      ans.second++;
    }
    return;
  }
  for (int i = 0; i < node[index].size(); i++) {
    dfs(node[index][i], depth + 1);
  }
  return;
}

int main() {
  scanf("%d %lf %lf", &n, &p, &r);
  r /= 100;
  node.resize(n);
  for (int i = 0; i < n; i++) {
    int num, k;
    cin >> num;
    if (!num)  continue;
    for (int j = 0; j < num; j++) {
      cin >> k;
      node[i].push_back(k);
    }
  }
  dfs(0, 0);
  printf("%.4f %d", ans.first, ans.second);
  return 0;
}