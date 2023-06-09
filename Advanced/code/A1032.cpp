#include <bits/stdc++.h>
using namespace std;
vector<char> d(100005);
vector<int> nxt(100005);

// 测试点5：有可能数据相同但是地址不相同
void getWord(string &a, int first, vector<int> &list) {
  while (first != -1) {
    list.push_back(first);
    a.push_back(d[first]);
    first = nxt[first];
  };
  return;
}

int main() {
  int addr1, addr2, n;
  cin >> addr1 >> addr2 >> n;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    cin >> d[temp] >> nxt[temp];
  }
  string a1, a2;
  vector<int> list1, list2;
  getWord(a1, addr1, list1);
  getWord(a2, addr2, list2);
  int id1 = a1.size() - 1, id2 = a2.size() - 1;
  if (a1[id1] != a2[id2]) {
    cout << -1;
    return 0;
  }
  while (id1 >= 0 && id2 >= 0 && a1[id1] == a2[id2] && list1[id1] == list2[id2]) {
    id1--;
    id2--;
  }
  printf("%05d", list1[id1+1]);
  return 0;
}