#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
ll bpow(ll a, ll b){
  if(!b){
    return 1;
  } if(b & 1){
    return a*bpow(a, b-1);
  } return bpow(a*a, b/2);
}
int IsPrime(ll n){
  ll d = 2;
  while(d*d <= n and n % d != 0){
    d++;
  }
  if(d*d > n && n > 1){
    return 1;
  }
  return 0;
}
int main(){
  int n;
  cin >> n;
  if(n == 0){
    cout << "000000000002";
  }
  else{
    ll x;
    cin >> x;
    int cnt = 12 - n;
    ll j = bpow(10, cnt)*x;
    ll u = bpow(10, cnt)*x;
    while(j < u+611){
      int q = IsPrime(j);
      if(q == 1){
        cout << setw(12) << setfill('0') << j;
        j = u+611;
      }
      j += 1;
    }
  }
}