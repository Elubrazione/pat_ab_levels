#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 1;
vector<bool> vis(maxn, false);
vector<int> father(maxn, 0), isRoot(maxn, 0);

int findFather(int x) {
  int a = x;
  while (x != father[x])
    x = father[x];
  while (a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

void Union(int a, int b) {
  int faa = findFather(a);
  int fab = findFather(b);
  if (faa != fab) {
    father[faa] = fab;
  }
}

void init() {
  for (int i = 1; i <= maxn; i++)
    father[i] = i;
}

pair<int, int> countTrees() {
  int ans = 0, birds = 0;
  for (int i = 1; i <= maxn; i++) {
    if (vis[i]) {
      isRoot[findFather(i)]++;
      birds++;
    }
  }
  for (int i = 1; i <= maxn; i++)
    if (isRoot[i])  ans++;
  pair<int, int> num = make_pair(ans, birds);
  return num;
}

int main() {
  int n, k, b, q, c1, c2;
  cin >> n;
  init();
  for (int i = 0; i < n; i++) {
    cin >> k;
    if (k != 0) {
      cin >> c1;
      vis[c1] = true;
    }
    for (int j = 1; j < k; j++) {
      cin >> c2;
      vis[c2] = true;
      Union(c1, c2);
      c1 = c2;
    }
  }
  pair<int, int> ans = countTrees();
  cout << ans.first << " " << ans.second << endl;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> c1 >> c2;
    if (findFather(c1) == findFather(c2))
      cout << "Yes" << endl;
    else  cout << "No" << endl;
  }
  return 0;
}