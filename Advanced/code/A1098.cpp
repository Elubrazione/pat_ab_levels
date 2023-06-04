#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> origin, sorted, more;

void downAdjust(int low, int high) {
  int i = low, j = i * 2;
  while(j <= high) {
    if (j + 1 <= high && more[j+1] > more[j])
      j++;
    if (more[j] > more[i]) {
      swap(more[j], more[i]);
      i = j;
      j = i * 2;
    } else {
      break;
    }
  }
  return;
}

bool insertSort() {
  bool fg = false;
  for (int i = 1; i < n; i++) {
    if (i != 1 && origin == sorted)
      fg = true;
    int temp = origin[i], j = i;
    while(j > 0 && origin[j-1] > temp) {
      origin[j] = origin[j-1];
      j--;
    }
    origin[j] = temp;
    if (fg)  return true;
  }
  return false;
}

void heapSort() {
  sorted.insert(sorted.begin(), 0);
  bool fg = false;
  for (int i = n; i > 1; i--) {
    if (i != n && more == sorted)
      fg = true;
    swap(more[i], more[1]);
    downAdjust(1, i - 1);
    if (fg)  break;
  }
  for (int i = 1; i <= n; i++) {
    cout << more[i];
    if (i != n)  cout << " ";
  }
  return;
}

int main() {
  cin >> n;
  int k;
  more.push_back(0);
  for (int i = 0; i < n; i++) {
    cin >> k;
    origin.push_back(k);
    more.push_back(k);
  }
  for (int i = 0; i < n; i++) {
    cin >> k;
    sorted.push_back(k);
  }
  bool fg = insertSort();
  if (fg) {
    cout << "Insertion Sort" << endl;
    for (int i = 0; i < n; i++) {
      cout << origin[i];
      if (i != n-1)  cout << " ";
    }
  } else {
    cout << "Heap Sort" << endl;
    for (int i = n/2; i >= 1; i--)
      downAdjust(i, n);
    heapSort();
  }
  return 0;
}