#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
vector<vector<int>> g;
vector<double> p;
void walk(int u, int par, double p_par, int d){
  if(g[u].size() == 1){
    p[d] += p_par;
    return; 
  }
  int t = g[u].size() - 1;
  for(int v : g[u]){
    if(v == par){
      continue;
    } 
    walk(v, u, double(p_par)/double(t), d+1);
  }
}
 
int main(){
  int n;
  cin >> n;
  p.resize(n+1);
  g.resize(n+1);
  for(int i=0, a, b; i<n-1; i++){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  g[0].push_back(1);
  g[1].push_back(0);
  walk(1, 0, 1, 0);
  double ans=0;
  for(int i=0; i<p.size(); i++){
    ans += p[i]*i;
  }
  cout << setprecision(7) << ans;
}