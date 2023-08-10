#include <bits/stdc++.h>
using namespace std;

struct Mooncake {
  double total_price;
  double price;
  double amounts;
};
vector<Mooncake> cakes;

int main() {
  int n;
  double d;
  cin >> n >> d;
  cakes.resize(n);
  for (int i = 0; i < n; i++)
    cin >> cakes[i].amounts;
  for (int i = 0; i < n; i++) {
    cin >> cakes[i].total_price;
    cakes[i].price = cakes[i].total_price / cakes[i].amounts;
  }
  sort(cakes.begin(), cakes.end(), [&](Mooncake a, Mooncake b) {
    return a.price > b.price;
  });

  double profits = 0;
  for (int i = 0; i < n; i++) {
    if (cakes[i].amounts < d) {
      profits += cakes[i].total_price;
      d -= cakes[i].amounts;
    } else {
      profits += d * cakes[i].price;
      break;
    }
  }
  printf("%.2f", profits);
  return 0;
}