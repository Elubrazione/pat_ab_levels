#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int n, id, k;
vector<int> info(N), vis(N, 0);
vector<bool> p(N + 1, false);

void findPrime() {
  for (int i = 2; i <= N; i++) {
    if (!p[i]) {
      for (int j = i + i; j <= N; j += i)
        p[j] = true;
    }
  }
  return;
}

int main() {
  cin >> n;
  findPrime();
  for (int i = 0; i < n; i++) {
    scanf("%d", &id);
    info[id] = i;
    vis[id] = 1;
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    scanf("%d", &id);
    if (!vis[id])
      printf("%04d: Are you kidding?\n", id);
    else if (vis[id] == -1)
      printf("%04d: Checked\n", id);
    else {
      if (info[id] == 0)
        printf("%04d: Mystery Award\n", id);
      else if (p[info[id]+1] == false)
        printf("%04d: Minion\n", id);
      else
        printf("%04d: Chocolate\n", id);
      vis[id] = -1;
    }
  }
  return 0;
}