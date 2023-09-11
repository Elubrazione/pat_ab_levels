// 得分：28/30
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> num;

int main() {
  int n, a, b, k;
  cin >> n;
  vector<int> hash1(n + 1, 0);
  vector<int> children(n + 1, -1);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    hash1[a]++; hash1[b]++;
    if (a > 9 || b > 9)
      num.push_back(a > 9? make_pair(a, b): make_pair(b, a));
    else if (a < b)  num.push_back(make_pair(a, b));
    else  num.push_back(make_pair(b, a));
  }
  sort(num.begin(), num.end(), [&](auto a, auto b) {
    if (a.first > 9 || b.first > 9)
      return a.first > b.first;
    else
      return a.first == b.first? a.second < b.second: a.first < b.first;
  });
  for (int i = 0; i < n; i = k) {
    k = i + 1;
    if (num[i].first > 9 || hash1[num[i].first] == 1) {
      children[num[i].first] = num[i].second;
    } else if (num[i].second > 9 || hash1[num[i].second] == 1) {
      children[num[i].second] = num[i].first;
    } else if (num[i].first == 0 && num[i].second != 0){
      children[num[i].second] = 0;
    } else if (children[num[i].first] == -1) {
      children[num[i].first] = num[i].second;
      for (k = i + 1; k < n && num[k].first == num[k-1].first; k++)
        children[num[k].second] = num[k].first;
    } else {
      children[num[i].second] = num[i].first;
    }
  }
  for (int i = 1; i < children.size(); i++)
    printf("%d", children[i]);
  return 0;
}