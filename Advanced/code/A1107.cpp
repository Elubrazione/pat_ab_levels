#include <bits/stdc++.h>
using namespace std;
vector<int> father, isRoot;

int findFather(int x) {
  int a = x;
  while(x != father[x])
    x = father[x];
  while(a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

void union2(int a, int b) {
  int fa = findFather(a);
  int fb = findFather(b);
  if (fa != fb) {
    father[fa] = fb;  // a -> b
  }
  return;
}

int main() {
  int n, k, ans = 0;
  cin >> n;
  father.resize(n + 1);
  isRoot.resize(n + 1);
  vector<int> course(1001, 0);
  for (int i = 1; i <= n; i++)
    father[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d:", &k);
    int a;
    for (int j = 0; j <k; j++) {
      cin >> a;
      if (course[a] == 0) {
        course[a] = i;
      }
      union2(i, findFather(course[a]));
    }
  }
  for (int i = 1; i <= n; i++)
    isRoot[findFather(i)]++;
  for (int i = 1; i <= n; i++)
    if (isRoot[i] != 0)
      ans++;
  sort(isRoot.begin(), isRoot.end(), [&](int a, int b) {
    return a > b;
  });
  cout << ans << endl;
  for (int i = 0; i < ans; i++) {
    cout << isRoot[i];
    if (i != ans - 1)  cout << " ";
  }
  return 0;
}