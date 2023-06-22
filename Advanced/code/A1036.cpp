#include <bits/stdc++.h>
using namespace std;

struct Student {
  string name;
  char gender;
  string UID;
  int grade;
  Student(
    string _n, char _g, string _u, int _s
  ): name(_n), gender(_g), UID(_u), grade(_s) {}
};
vector<Student> female, male;

int main() {
  int n, d;
  cin >> n;
  string a, b;
  char c;
  for (int i = 0;i < n; i++) {
    cin >> a >> c >> b >> d;
    if (c == 'M')
      male.push_back(Student(a, c, b, d));
    else
      female.push_back(Student(a, c, b, d));
  }
  sort(female.begin(), female.end(), [&] (Student a, Student b) {
    return a.grade > b.grade;
  });
  sort(male.begin(), male.end(), [&] (Student a, Student b) {
    return a.grade < b.grade;
  });
  if (!female.size())  cout << "Absent" << endl;
  else  cout << female[0].name << " " << female[0].UID << endl;
  if (!male.size())  cout << "Absent" << endl;
  else  cout << male[0].name << " " << male[0].UID << endl;
  if (!female.size() || !male.size())  cout << "NA";
  else  cout << abs(male[0].grade - female[0].grade);
  return 0;
}