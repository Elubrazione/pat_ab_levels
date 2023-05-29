#include <bits/stdc++.h>
using namespace std;
vector<double> vec(1001, 0);

int main() {
  for (int i = 0; i < 2; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int exp;
      double coe;
      scanf("%d %lf", &exp, &coe);
      vec[exp] += coe;
    }
  }
  int nums = 0;
  for (int i = 0; i < 1001; i++)
    if (vec[i] != 0)  nums++;
  cout << nums;
  for (int i = 1000; i >= 0; i--) 
    if (vec[i])
      printf(" %d %.1f", i, vec[i]);
  return 0;
}