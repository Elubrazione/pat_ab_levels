#include <bits/stdc++.h>
using namespace std;
int n, m, k, ds, ans = -1;
double minAvg = INT_MAX, minDtc = -1;
vector<int> d, vis;
vector<vector<int>> G;

int stringToInt(string s) {
  if (s[0] == 'G') {
    if (s.size() == 3)
      return n + 10;
    else
      return s[1] - '0' + n;
  } else {
    return stoi(s);
  }
}

void Dijkstra(int s) {
  d[s] = 0;
  for (int i = 1; i <= n + m; i++) {
    int u = -1, mx = INT_MAX;
    for (int j = 1; j <= n + m; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (int v = 1; v <= n + m; v++) {
      if (vis[v] == false && G[u][v] != INT_MAX) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> k >> ds;
  d.resize(n + m + 1);
  vis.resize(n + m + 1);
  G.resize(n + m + 1, vector<int>(n + m + 1, INT_MAX));
  for (int i = 0; i < k; i++) {
    string temp1, temp2;
    cin >> temp1 >> temp2;
    int dtc;
    cin >> dtc;
    int a = stringToInt(temp1);
    int b = stringToInt(temp2);
    G[a][b] = dtc;
    G[b][a] = dtc;
  }

  // 枚举每个加油站，调用Dijkstra求到各居民住处的最小距离
  for (int i = n + 1; i <= n + m; i++) {
    fill(d.begin(), d.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
    Dijkstra(i);
    double avg = 0.0;
    int mx = INT_MAX, fg = 0;
    for (int j = 1; j <= n; j++) {
      if (d[j] > ds) {
        fg = 1;
        break;
      }
      avg += d[j] * 1.0 / n;
      if (d[j] < mx)  mx = d[j];
    }
    if (fg)  continue;
    if (mx > minDtc || (mx == minDtc && avg < minAvg)) {
      minAvg = avg;
      minDtc = (double)mx;
      ans = i;
    }
  }
  if (ans == -1)  cout << "No Solution";
  else {
    printf("G%d\n", ans - n);
    printf("%.1f %.1f", minDtc, minAvg);
  }
  return 0;
}