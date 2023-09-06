#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
int vis[maxn], n, m, minStops, minTrans, st, ed;;
vector<vector<int>> v(maxn);
unordered_map<int, int> line;
vector<int> path, ans;

int transferCnt() {
  int cnt = -1, preLine = 0;  // 定义成-1初始值是因为i=1时一定不等于0
  for (int i = 1; i < path.size(); i++) {
    if (line[path[i-1] * maxn + path[i]] != preLine)
      cnt++;
    preLine = line[path[i-1] * maxn + path[i]];
  }
  return cnt;
}

void dfs(int now, int stops) {
  if (now == ed) {
    if (stops < minStops || (stops == minStops && transferCnt() < minTrans)) {
      minStops = stops;
      minTrans = transferCnt();
      ans = path;
    }
    return;
  }
  for (auto p: v[now]) {
    if (!vis[p]) {
      vis[p] = 1;
      path.push_back(p);
      dfs(p, stops + 1);
      path.pop_back();
      vis[p] = 0;
    }
  }
}

void printTool() {
  cout << minStops << endl;
  int preLine = 0, preTrans = st;
  for (int i = 1; i < ans.size(); i++) {
    if (line[ans[i-1] * maxn + ans[i]] != preLine) {
      if (preLine != 0)
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTrans, ans[i-1]);
      preLine = line[ans[i-1] * maxn + ans[i]];
      preTrans = ans[i-1];
    }
  }
  printf("Take Line#%d from %04d to %04d.\n", preLine, preTrans, ed);
  return;
}

int main() {
  int k, pre, temp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m >> pre;
    for (int j = 1; j < m; j++) {
      cin >> temp;
      v[pre].push_back(temp);
      v[temp].push_back(pre);
      line[pre*maxn+temp] = line[temp*maxn+pre] = i + 1;
      pre = temp;
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> st >> ed;
    minStops = maxn, minTrans = maxn;
    path.clear();
    path.push_back(st);
    vis[st] = 1;
    dfs(st, 0);
    vis[st] = 0;
    printTool();
  }
  return 0;
}