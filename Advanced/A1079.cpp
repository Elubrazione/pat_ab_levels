#include <bits/stdc++.h>
using namespace std;
int n;
double p, r, prices;

struct TreeNode {
  vector<int> child;
  int sales;
};
vector<TreeNode> chain;

void dfs(int index, int depth) {
  if (!chain[index].child.size()) {
    // cout << index << " " << depth << " " << chain[index].sales << endl;
    prices +=  pow(1+r, depth) * chain[index].sales * p;
    return;
  }
  for (int i = 0; i < chain[index].child.size(); i++) {
    dfs(chain[index].child[i], depth + 1);
  }
  return;
}

int main() {
  scanf("%d %lf %lf", &n, &p, &r);
  r /= 100;
  chain.resize(n);
  for (int i = 0; i < n; i++) {
    int num, k;
    cin >> num;
    if (num) {
      for (int j = 0; j < num; j++) {
        cin >> k;
        chain[i].child.push_back(k);
        chain[i].sales = -1;
      }
    } else {
      cin >> k;
      chain[i].sales = k;
    }
  }
  dfs(0, 0);
  printf("%.1f", prices);
  return 0;
}