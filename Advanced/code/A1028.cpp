#include <bits/stdc++.h>
using namespace std;

struct Student {
  string id;
  string name;
  int grade;
};

int main() {
  int a, b;
  cin >> a >> b;
  vector<Student> vec;
  for (int i = 0; i < a; i++) {
    Student cur;
    cin >> cur.id >> cur.name >> cur.grade;
    vec.push_back(cur);
  }
  sort(vec.begin(), vec.end(), [&] (Student i1, Student i2) {
    if (b == 1)
      return i1.id < i2.id;
    else if (b == 2)
      return i1.name <= i2.name;
    else
      return i1.grade <= i2.grade;
  });
  for (int i = 0; i < a; i++) {
    cout << vec[i].id << " " << vec[i].name << " " << vec[i].grade;
    if (i != a - 1)
      cout << endl;
  }
  return 0;
}