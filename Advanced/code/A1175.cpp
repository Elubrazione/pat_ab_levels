#include <bits/stdc++.h>
using namespace std;
struct Node {
  int u;
  int voucher;
  int score;
  Node (int _u, int _v, int _s): u(_u), voucher(_v), score(_s) {}
};
const int maxn = 0x3ffffff;
unordered_set<int> starts;
vector<int> inDegree, vis, d, pre, vouch;
vector<vector<Node>> G;

bool isDAG(int n) {
  queue<int> q;
  int cnt = 0;
  for (auto p: starts)  q.push(p);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cnt++;
    for (auto p: G[u]) {
      inDegree[p.u]--;
      if (!inDegree[p.u])
        q.push(p.u);
    }
  }
  return cnt == n;
}

void Dijkstra(int s) {
  vis.resize(s + 1, false);
  d.resize(s + 1, maxn);
  pre.resize(s + 1, maxn);
  vouch.resize(s + 1, 0);
  d[s] = 0;
  for (int i = 0; i <= s; i++) {
    int u = -1, mx = maxn;
    for (int j = 0; j <= s; j++) {
      if (vis[j] == false && d[j] < mx) {
        u = j;
        mx = d[j];
      }
    }
    if (u == -1)  return;
    vis[u] = true;
    for (auto p: G[u]) {
      if (vis[p.u]) continue;
      if (d[u] + p.score < d[p.u]) {
        d[p.u] = d[u] + p.score;
        vouch[p.u] = vouch[u] + p.voucher;
        pre[p.u] = u;
      } else if (d[u] + p.score == d[p.u] && vouch[p.u] < vouch[u] + p.voucher) {
        vouch[p.u] = vouch[u] + p.voucher;
        pre[p.u] = u;
      }
    }
  }
}

void dfs(int st, int i, vector<int> &path) {
  if (i == st)  return;
  dfs(st, pre[i], path);
  path.push_back(i);
}

int main() {
  int n, m, t1, t2, s, d, k;
  cin >> n >> m;
  G.resize(n + 1);
  inDegree.resize(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> t1 >> t2 >> s >> d;
    G[t1].push_back(Node(t2, d, s));
    inDegree[t2]++;
  }
  for (int i = 0; i < n; i++)
    if (!inDegree[i])
      starts.insert(i);
  cin >> k;
  if (isDAG(n)) {
    printf("Okay.\n");
    for (auto p: starts)  G[n].push_back(Node(p, 0, 0));
    Dijkstra(n);
    for (int i = 0; i < k; i++) {
      cin >> t1;
      if (starts.count(t1))
        printf("You may take test %d directly.\n", t1);
      else {
        vector<int> ans;
        dfs(n, t1, ans);
        cout << ans[0];
        for (int j = 1; j < ans.size(); j++)
          printf("->%d", ans[j]);
        cout << endl;
      }
    }
  } else {
    printf("Impossible.\n");
    for (int i = 0; i < k; i++) {
      cin >> t1;
      if (starts.count(t1))
        printf("You may take test %d directly.\n", t1);
      else printf("Error.\n");
    }
  }
  return 0;
}