#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> online, mid, last, name;
vector<pair<string, int>> gtotal;

int main() {
  int p, m, n;
  double score;
  string uid;
  cin >> p >> m >> n;
  for (int i = 0; i < p; i++) {
    cin >> uid >> score;
    if (score >= 200) online[uid] = score;
  }
  for (int i = 0; i < m; i++) {
    cin >> uid >> score;
    mid[uid] = score;
  }
  for (int i = 0; i < n; i++) {
    cin >> uid >> score;
    last[uid] = score;
    if (online[uid] && mid.find(uid) != mid.end() && mid[uid] > last[uid]) {
      int sum = int(mid[uid] * 0.4 + last[uid] * 0.6 + 0.5);
      if (sum >= 60)  name[uid] = 1;
    } else if (online[uid] && ((mid.find(uid) != mid.end() && last[uid] >= mid[uid]) || mid.find(uid) == mid.end())) {
      if (score >= 60)  name[uid] = 1;
    }
  }
  for (auto it = name.begin(); it != name.end(); it++) {
    string s = it -> first;
    if (mid.find(s) != mid.end() && mid[s] > last[s])
      gtotal.push_back(make_pair(s, int(mid[s] * 0.4 + last[s] * 0.6 + 0.5)));
    else  gtotal.push_back(make_pair(s, last[s]));
  }
  sort(gtotal.begin(), gtotal.end(), [&](const auto a, const auto b) {
    if (a.second != b.second)
      return a.second > b.second;
    else  return a.first < b.first;
  });
  for (auto p: gtotal) {
    printf("%s %d ", p.first.c_str(), online[p.first]);
    if (mid.find(p.first) == mid.end())  printf("-1 ");
    else  printf("%d ", mid[p.first]);
    printf("%d %d\n", last[p.first], p.second);
  }
  return 0;
}