#include <bits/stdc++.h>
using namespace std;

struct Person {
  int height;
  string name;
};
vector<Person> vec;

int main() {
  int n, m, k;
  cin >> n >> k;
  vec.resize(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i].name >> vec[i].height;
  sort(vec.begin(), vec.end(), [&](Person a, Person b) {
    return a.height == b.height? a.name < b.name: a.height > b.height;
  });

  int cnt = 0;
  for (int row = 0; row < k; row++) {
    if (!row) m = n - n / k * (k - 1);
    else  m = n / k;
    vector<string> col(m);
    col[m/2] = vec[cnt++].name;

    int k = 1;
    for (int i = 1; k < m; i++) {
      if (m / 2 - i >= 0) {
        col[m/2-i] = vec[cnt++].name;
        k++;
      }
      if (m / 2 + i < m) {
        col[m/2+i] = vec[cnt++].name;
        k++;
      }
    }
    cout << col[0];
    for (int q = 1; q < m; q++)
      cout << " " << col[q];
    cout << endl;
  }
  return 0;
}