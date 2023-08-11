#include <bits/stdc++.h>
using namespace std;

struct Person {
  int height;
  string name;
};
vector<Person> vec;

int main(){
  int n, k, m;
  cin >> n >> k;

  vec.resize(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i].name >> vec[i].height;

  // When there are many people having the same height,
  // they must be ordered in alphabetical (increasing) order of their names,
  // and it is guaranteed that there is no duplication of names.

  // 也就是说当有多个人身高一样的时候，必须按照名字的字典顺序排列
  // 由于左边是身高高的，从左到右字典顺序增加，因此身高相同时，名字字典序小的就在左边
  sort(vec.begin(), vec.end(), [&](Person a, Person b) {
    return a.height == b.height? a.name < b.name: a.height > b.height;
  });

  int cnt = 0;
  for (int i = 0; i < k; i++) {
    if (!i)  m = n - n / k * (k-1);
    else  m = n / k;
    vector<string> columns(m);
    // 中间位置是m/2+1，数组下标就是m/2
    columns[m/2] = vec[cnt].name;

    int j = m / 2 - 1;
    for (int k = cnt + 1; k < cnt + m; k += 2)
      columns[j--] = vec[k].name;
    j = m / 2 + 1;
    for (int k = cnt + 2; k < cnt + m; k += 2)
      columns[j++] = vec[k].name;

    cout << columns[0];
    for (int k = 1; k < m; k++)
      cout << " " << columns[k];
    cout << endl;
    cnt += m;
  }
  return 0;
}