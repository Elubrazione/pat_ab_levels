#include <bits/stdc++.h>
using namespace std;
vector<int> num;
vector<vector<int>> matrix;

int main() {
  int N;
  cin >> N;
  num.resize(N);
  for (int i = 0; i < N; i++)  cin >> num[i];
  if (N == 1) {
    cout << num[0];
    return 0;
  }
  sort(num.begin(), num.end(), greater<int>());
  int m = (int)ceil(sqrt(N * 1.0));
  while (N % m)  m++;
  int  n = N / m;
  matrix.resize(m, vector<int>(n, 0));

  int i = 0, j = 0, now = 0;
  int up = 0, down = m - 1, left = 0, right = n - 1;
  while (now < N) {
    while (now < N && j < right) {
      matrix[i][j] = num[now++];
      j++;
    }
    while (now < N && i < down) {
      matrix[i][j] = num[now++];
      i++;
    }
    while (now < N && j > left) {
      matrix[i][j] = num[now++];
      j--;
    }
    while (now < N && i > up) {
      matrix[i][j] = num[now++];
      i--;
    }
    up++, down--, left++, right--;
    i++, j++;
    if (now == N - 1)  matrix[i][j] = num[now++];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j];
      if (j != n - 1)  cout << " ";
      else  cout << endl;
    }
  }
  return 0;
}