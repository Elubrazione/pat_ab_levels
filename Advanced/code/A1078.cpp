// Quadratic probing (with positive increments only)
// 二次方探测，[hashKey+/-(step * step)] % size，其中size从1到size-1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
vector<bool> p(maxn, false), vis;

// 1既不是素数也不是合数，要特判（测试点1）；
// 虽然说N最大是1e4，但是1e4有可能是合数，调整后会变大，因此实际N要大一些（测试点2和3）

void findPrime() {
  p[1] = true;
  for (int i = 2; i <= maxn; i++) {
    if (!p[i]) {
      for (int j = i + i; j <= maxn; j += i)
        p[j] = true;
    }
  }
}

int main() {
  findPrime();
  int size, n, cur;
  cin >> size >> n;
  while (p[size]) size++;
  vis.resize(size, false);

  for (int i = 0; i < n; i++) {
    cin >> cur;
    if (!vis[cur%size]) {
      vis[cur%size] = true;
      cout << cur % size;
    } else {
      int j;
      for (j = 1; j < size; j++) {
        int newhash = (cur % size + j * j) % size;
        if (!vis[newhash]) {
          vis[newhash] = true;
          cout << newhash;
          break;
        }
      }
      if (j == size)  cout << '-';
    }
    if (i != n - 1) cout << " ";
  }
  return 0;
}