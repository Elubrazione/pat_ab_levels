#include <bits/stdc++.h>
using namespace std;
int n, k, idx = 0;
string sta;
map<string, int> stringToInt;
map<int, string> intToString;
vector<int> joy, d, vis, tempPath, path, num;
vector<vector<int>> G, pre;

int stoiTools(string str) {
  if (stringToInt[str] == 0) {
    stringToInt[str] = idx;
    intToString[idx] = str;
    return idx++;
  } else {
    return stringToInt[str];
  }
}

void Dijkstra(int s) {
  d[s] = 0;
  num[s] = 1;
  for (int i = 0; i < n; i++) {
    int u = -1, mx = INT_MAX;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && G[u][v] != INT_MAX) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
          pre[v].clear();
          pre[v].push_back(u);
          num[v] = num[u];
        } else if (d[u] + G[u][v] == d[v]) {
          pre[v].push_back(u);
          num[v] += num[u];
        }
      }
    }
  }
  return;
}

int ansJoy = 0;
double ansAvg = 0.0;
void dfs(int v) {
  if (v == stringToInt[sta]) {
    tempPath.push_back(v);
    int numsize = tempPath.size();
    double avgJoy = 0.0;
    int mxJoy = 0;
    for (int i = numsize - 1; i >= 0; i--) {
      int cur = tempPath[i];
      avgJoy += joy[cur] * 1.0 / (numsize - 1);
      mxJoy += joy[cur];
    }
    if (mxJoy > ansJoy) {
      ansJoy = mxJoy;
      ansAvg = ansJoy * 1.0 / (numsize - 1);
      path = tempPath;
    } else if (mxJoy == ansJoy && avgJoy > ansAvg) {
      ansAvg = avgJoy;
      path = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  tempPath.push_back(v);
  for (int i = 0; i < pre[v].size(); i++)
    dfs(pre[v][i]);
  tempPath.pop_back();
  return;
}

int main() {
  cin >> n >> k >> sta;
  joy.resize(n, 0);
  num.resize(n, 0);
  d.resize(n, INT_MAX);
  vis.resize(n, false);
  pre.resize(n);
  G.resize(n, vector<int>(n, INT_MAX));
  int s = stoiTools(sta), hp;
  for (int i = 1; i < n; i++) {
    string ss;
    cin >> ss >> hp;
    int cur = stoiTools(ss);
    joy[cur] = hp;
  }
  for (int i = 0;i < k; i++) {
    string s1, s2;
    cin >> s1 >> s2 >> hp;
    int a = stringToInt[s1], b = stringToInt[s2];
    G[a][b] = hp;
    G[b][a] = hp;
  }
  Dijkstra(s);
  int e = stringToInt["ROM"];
  dfs(e);
  printf("%d %d %d %d\n", num[e], d[e], ansJoy, (int)ansAvg);
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << intToString[path[i]];
    if (i)  cout << "->";
  }
  return 0;
}