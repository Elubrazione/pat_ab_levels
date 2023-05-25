#include <bits/stdc++.h>
using namespace std;

typedef struct
{
  string name;
  string uid;
  int grade;
} Student;

int main()
{
  int n;
  cin >> n;
  vector<Student> stu(n);
  for (int i = 0; i < n; i++) {
    cin >> stu[i].name >> stu[i].uid >> stu[i].grade;
  }
  sort(stu.begin(), stu.end(), [&](Student a, Student b) {
    return a.grade > b.grade;
  });
  cout << stu[0].name << " " << stu[0].uid << endl;
  cout << stu[n - 1].name << " " << stu[n - 1].uid;
  return 0;
}