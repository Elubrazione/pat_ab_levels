#include <bits/stdc++.h>
using namespace std;
vector<string> hash_low = {
  "tret",
  "jan", "feb", "mar", "apr", "may", "jun",
  "jly", "aug", "sep", "oct", "nov", "dec"
};
vector<string> hash_high = {
  "",
  "tam", "hel", "maa", "huh", "tou", "kes",
  "hei", "elo", "syy", "lok", "mer", "jou"
};

unordered_map<string, int> n_hash_low = {
  {"tret", 0},
  {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4},
  {"may", 5}, {"jun", 6}, {"jly", 7}, {"aug", 8},
  {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12}
};
unordered_map<string, int> n_hash_high = {
  {"tam", 1}, {"hel", 2}, {"maa", 3},
  {"huh", 4}, {"tou", 5}, {"kes", 6},
  {"hei", 7}, {"elo", 8}, {"syy", 9},
  {"lok", 10}, {"mer", 11}, {"jou", 12}
};

string mars2Earth(string s) {
  int sum;
  if (s.size() > 3)
    sum = n_hash_high[s.substr(0, 3)] * 13 + n_hash_low[s.substr(4, s.size()-4)];
  else if (n_hash_low.find(s) == n_hash_low.end())
    sum = n_hash_high[s] * 13;
  else
    sum = n_hash_low[s];

  string num_earth;
  do {
    num_earth.push_back((sum % 10) + '0');
    sum /= 10;
  } while (sum);
  reverse(num_earth.begin(), num_earth.end());
  return num_earth;
}

string earth2Mars(string s) {
  // 一个十进制数字字符串，要先转换成数字，再换成十三进制，再换成对应的火星文
  int product = 1, sum = 0;
  for (int i = s.size()-1; i >= 0; i--) {
    sum += (s[i] - '0') * product;
    product *= 10;
  }

  vector<int> num13;
  do {
    num13.push_back(sum % 13);
    sum /= 13;
  } while (sum);

  string num_mars;
  for (int i = num13.size()-1; i >= 0; i--) {
    if (i) {
      num_mars += hash_high[num13[i]];
      num_mars.push_back(' ');
    }
    else {
      if (num13[i] || !num_mars.size())
        num_mars += hash_low[num13[i]];
      else
        num_mars = num_mars.substr(0, num_mars.size()-1);
    }
  }
  return num_mars;
}

int main() {
  int n;
  cin >> n;
  char c = getchar();
  string num, num_final;
  for (int i = 0; i < n; i++) {
    getline(cin, num);
    if (num[0] >= '0' && num[0] <= '9')
      num_final = earth2Mars(num);
    else
      num_final = mars2Earth(num);
    cout << num_final;
    if (i != n - 1)  cout << endl;
  }
  return 0;
}