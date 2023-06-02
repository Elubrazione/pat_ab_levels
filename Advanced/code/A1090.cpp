#include <bits/stdc++.h>
using namespace std;
int n, root;
double p, r;
pair<double, int> ans = {0.0, 0};
vector<vector<int>> node;

void dfs(int index, int depth) {
  if (node[index].size() == 0) {
    double price = pow(1+r, depth) * p;
    if (price > ans.first) {
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
    int k;
    cin >> k;
    if (k != -1)  node[k].push_back(i);
    else  root = i;
  }
  dfs(root, 0);
  printf("%.2f %d", ans.first, ans.second);
  return 0;
}