#include <bits/stdc++.h>
using namespace std;
int n, r, k, m;
set<int> s;
vector<int> region;
vector<vector<int>> G;

bool judge() {
  for (int i = 1; i <= n; i++)
    for (auto p: G[i])
      if (region[p] == region[i])
        return false;
  return true;
}

int main() {
  cin >> n >> r >> k;
  G.resize(n + 1);
  region.resize(n + 1, 0);
  int a, b;
  for (int i = 0; i < r; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    s.clear();
    for (int j = 1; j <= n; j++) {
      cin >> region[j];
      s.insert(region[j]);
    }
    if (s.size() != k) {
      if (s.size() > k) printf("Error: Too many species.\n");
      else  printf("Error: Too few species.\n");
      continue;
    }
    bool flag = judge();
    printf("%s\n", flag? "Yes": "No");
  }
  return 0;
}