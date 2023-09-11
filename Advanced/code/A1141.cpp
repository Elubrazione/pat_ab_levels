#include <bits/stdc++.h>
using namespace std;
unordered_map<string, double> weighted_score;
unordered_map<string, int> num;

int main() {
  double score;
  int rank = 0, n;
  cin >> n;
  string uid, school;
  for (int i = 0; i < n; i++) {
    cin >> uid >> score >> school;
    for (int j = 0; j < school.length(); j++)
      school[j] = tolower(school[j]);
    num[school]++;
    if (uid[0] == 'A') {
      weighted_score[school] += score;
    } else if (uid[0] == 'T') {
      weighted_score[school] += score * 1.5;
    } else {
      weighted_score[school] += score * 1.0 / 1.5;
    }
  }

  vector<pair<string, int>> ans;
  for (auto it = weighted_score.begin(); it != weighted_score.end(); it++)
    ans.push_back(make_pair(it -> first, (int)(it -> second)));
  sort(ans.begin(), ans.end(), [&](auto a, auto b) {
    return a.second == b.second? (num[a.first] == num[b.first]? a.first < b.first: num[a.first] < num[b.first]): a.second > b.second;
  });

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    if (i && ans[i].second == ans[i-1].second) {}
    else  rank = i + 1;
    printf("%d %s %d %d\n", rank, ans[i].first.c_str(), (int)ans[i].second, num[ans[i].first]);
  }
  return 0;
}