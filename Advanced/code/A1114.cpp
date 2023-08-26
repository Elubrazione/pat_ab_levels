#include <bits/stdc++.h>
using namespace std;

struct Node {
  int id, fid, mid, sets, area;
  vector<int> child;
};
struct Res {
  int id, num;
  double area, sets;
  bool flag = false;
};

int n;
const int N = 10000;
vector<Res> ans(N);
vector<Node> info;
vector<bool> vis(N, false);
vector<int> father(N);

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
  int faA = findFather(a);
  int faB = findFather(b);
  // where ID is the smallest ID in the family
  if (faA > faB)
    father[faA] = faB;
  else if (faA < faB)
    father[faB] = faA;
  return;
}

void init() {
  for (int i = 0; i < N; i++)
    father[i] = i;
  return;
}

int main() {
  cin >> n;
  info.resize(n);
  init();

  int nchild, ichild, cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &info[i].id, &info[i].fid, &info[i].mid, &nchild);
    vis[info[i].id] = true;
    if (info[i].fid != -1) {
      vis[info[i].fid] = true;
      Union(info[i].fid, info[i].id);
    }
    if (info[i].mid != -1) {
      vis[info[i].mid] = true;
      Union(info[i].mid, info[i].id);
    }
    for (int j = 0; j < nchild; j++) {
      scanf("%d", &ichild);
      vis[ichild] = true;
      info[i].child.push_back(ichild);
      Union(ichild, info[i].id);
    }
    scanf("%d %d", &info[i].sets, &info[i].area);
  }
  for (int i = 0; i < n; i++) {
    int cur = findFather(info[i].id);
    ans[cur].id = cur;
    ans[cur].sets += info[i].sets;
    ans[cur].area += info[i].area;
    ans[cur].flag = true;
  }
  for (int i = 0; i < N; i++) {
    if (vis[i]) ans[findFather(i)].num++;
    if (ans[i].flag)  cnt++;
  }
  for (int i = 0; i < N; i++) {
    if (ans[i].flag) {
      ans[i].sets = (double)(ans[i].sets * 1.0 / ans[i].num);
      ans[i].area = (double)(ans[i].area * 1.0 / ans[i].num);
    }
  }
  sort(ans.begin(), ans.end(), [&](Res a, Res b) {
    if (a.area != b.area) return a.area > b.area;
    else  return a.id < b.id;
  });
  cout << cnt << endl;
  for(int i = 0; i < cnt; i++)
    printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].num, ans[i].sets, ans[i].area);
  return 0;
}