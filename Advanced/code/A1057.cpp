#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;
int block[sqrN] = {0}, table[maxn] = {0};
stack<int> st;

void Push(int x) {
  st.push(x);
  table[x]++;
  block[x/sqrN]++;
}

void Pop() {
  int x = st.top();
  st.pop();
  block[x/sqrN]--;
  table[x]--;
  cout << x << endl;
}

void PeekMedian(int x) {
  int sum = 0, idx = 0;
  while (sum + block[idx] < x)
    sum += block[idx++];
  int n = sqrN * idx;
  while (sum + table[n] < x)
    sum += table[n++];
  cout << n << endl;
}

int main() {
  string str;
  int num, x;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> str;
    if (str == "Push") {
      cin >> x;
      Push(x);
    } else if (str == "Pop") {
      if (st.empty())
        cout << "Invalid" << endl;
      else  Pop();
    } else {
      if (st.empty())
        cout << "Invalid" << endl;
      else {
        int k = st.size();
        if (k % 2)  k = (k + 1) / 2;
        else  k /= 2;
        PeekMedian(k);
      }
    }
  }
  return 0;
}