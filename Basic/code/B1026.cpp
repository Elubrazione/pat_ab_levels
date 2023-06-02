#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int time = (b-a)%100 >= 50? (b-a)/100+1: (b-a)/100;
  string ss = to_string(time%60);
  string mm = to_string((time/60)%60);
  string hh = to_string(time/3600);
  if (ss.size() < 2)  ss = "0" + ss;
  if (mm.size() < 2)  mm = "0" + mm;
  if (hh.size() < 2)  hh = "0" + hh;
  cout << hh << ":" << mm << ":" << ss;
  return 0;
}