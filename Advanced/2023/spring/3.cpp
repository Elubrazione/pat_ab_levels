#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int in[N], out[N];
int ans[N][N];
int n, m;

int main(){
  cin >> n >> m;
  while(m--){
    int a, b;
    cin >> a >> b;
    out[a]++;
    in[b]++;
  }
  map<int,string> m;
  for(int i = 0; i < n; i++){
    string v;
    cin >> v;
    m[i]=v;
  }
  set<string> s;
  for(int i = 0; i < n; i++)
    if(out[i] > in[i])
      s.insert(m[i]);
  for(auto i: s)
    cout << i << endl;
  return 0;
}