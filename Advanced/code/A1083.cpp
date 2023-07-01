#include <bits/stdc++.h>
using namespace std;

struct Student {
  string name;
  string id;
  int grade;
};

int main() {
  int n, left, right;
  cin >> n;
  vector<Student> vec, ans;
  for (int i = 0; i < n; i++) {
    Student cur;
    cin >> cur.name >> cur.id >> cur.grade;
    vec.push_back(cur);
  }
  cin >> left >> right;
  for (int i = 0; i < n; i++) {
    if (vec[i].grade >= left && vec[i].grade <= right)
      ans.push_back(vec[i]);
  }
  sort(ans.begin(), ans.end(), [&] (Student i1, Student i2) {
    return i1.grade >= i2.grade;
  });
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].name << " " << ans[i].id;
    if (i != ans.size() - 1)
      cout << endl;
  }
  if (!ans.size())
    cout << "NONE";
  return 0;
}