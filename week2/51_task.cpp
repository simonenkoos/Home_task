#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
int bpow(int a, int b){
  if(!b){
    return 1;
  }
  if(b & 1){
    return a*bpow(a, b-1);
  }
  return bpow(a*a, b >> 1);
}
int position(int x){
  int l = -1;
  int r = 17;
  while(r-l > 1){
    int m = (r+l) / 2;
    if( bpow(2, m) > x){
      r = m;
    } else{
      l = m;
    }
  }
  return l;
}
int main(){
  int n;
  cin >> n;
  vector<int> keys;
  map<int, int> f;
  for(int i=2; i*i<=n; i++){
    if(n%i == 0){
      keys.push_back(i);
    }
    while(n%i == 0){
      f[i]++;
      n /= i;
    }
  }
  if(n != 1){
    f[n]++;
    keys.push_back(n);
  }
  sort(keys.begin(), keys.end());
  vector<int> d;
  d.push_back(1);
  for( int i=0; i<keys.size(); i++){
    int l = d.size();
    for(int q=0; q<l; q++){
      for(int j=1; j<=f[keys[i]]; j++){
      d.push_back(d[q]*bpow(keys[i], j));
      }
    }
  }
  int ans = 0;
  for(int i:d){
    int k = position(i);
    if(k+1 & 1){ 
      k /= 2;
      if(i == (1 << k) * ((1 << (k+1)) - 1)){
        ans = max(ans, i);
      }
    }
  }
  cout << ans;
}