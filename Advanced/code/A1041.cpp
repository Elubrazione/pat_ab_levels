#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> ori, order(10001, 0);
  int num;
  cin >> num;
  while (num--) {
    int a;
    cin >> a;
    ori.push_back(a);
    if (order[a] == 0) {
      order[a] = ori.size();
    } else {
      order[a] = INT_MAX;
    }
  }
  sort(ori.begin(), ori.end(), [&] (int a, int b) {
    return order[a] < order[b];
  });
  if (order[ori[0]] == INT_MAX)
    cout << "None";
  else  cout << ori[0];
  return 0;
}