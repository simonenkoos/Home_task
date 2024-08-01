#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
int bin_search(vector<ll> &u, int a){
  int r, l, m;
  r = u.size()+1;
  l = 0;
  while(r-l > 1){
    m = (r+l)/2;
    if(u[m] > a){
      r = m;
    }else{
      l = m;
    } 
  } return l;
}
int gcd(int a, int b){
  if(!b){
    return a;
  } return gcd(b, a%b);
}
ll pow1(ll a, ll b){
  if(!b){
    return 1;
  } 
  if(b & 1){
    return a*pow1(a, b-1);
  } 
  return pow1(a*a, b >> 1);
}
int main(){
  int a, b, gcd1;
  cin >> a >> b;
  gcd1 = gcd(a, b);
  vector<ll> keys, u;
  map<int, int> f;
  for(int i = 2; i*i<=gcd1; i++){
    if(gcd1%i == 0){
      keys.push_back(i);
    }
    while(gcd1%i == 0){
      f[i]++;
      gcd1 /= i;
    }
  }
  if(gcd1 != 1){
    f[gcd1]++;
    keys.push_back(gcd1);
  }
  u.push_back(1);
  sort(keys.begin(), keys.end());
  for(int i=0; i<keys.size(); i++){
    int l = u.size();
    for(int j=0; j<l; j++){
      for(int q=f[keys[i]]; q>0; q--){
        u.push_back(u[j]*pow1(keys[i],q));
      }
    }
  }
  sort(u.begin(),u.end());
  u.push_back(10e9+1);
  int n, x, y; 
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    int l2 = bin_search(u, y);
    if(u[l2] >= x and u[l2] <= y){
      cout << u[l2] << '\n';
    }else{
      cout << -1 << '\n';
    }
  }
}