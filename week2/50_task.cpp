#include <iostream>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
  if(!b){
    return a;
  }
  return gcd(b, a%b);
}
int main(){
  int n;
  ll x, gcd1;
  cin >> n;
  cin >> gcd1;
  for(int i=1; i<n; i++){
    cin >> x;
    gcd1 = gcd(gcd1, x);
  }
  int cnt = 1;
  for(ll i=2, q; i*i <= gcd1; i++){
    q = 0;
    while(gcd1%i == 0){
      q++;
      gcd1 /= i;
    }
    cnt *= q+1;
  }
  if(gcd1 != 1){
    cnt *= 1+1;
  }
  cout << cnt;
}