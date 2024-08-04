#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 10e6+1;
int np[N];
int primes[N];
void resheto(){
  fill_n(np, N, 0);
  fill_n(primes, N, 0);
  for(ll i=2; i<N; i++){
    if(np[i] == 1){
      continue;
    }
    primes[i] = 1;
    for(ll j=i*i; j<N; j += i){
      np[j] = 1;
    }
  }
}
ll binsearch(ll x){
  ll r = 10e6+1;
  ll l = -1;
  while(r - l > 1){
    ll m = (r+l) / 2;
    if(m*m > x){
      r = m;
    } else{
      l = m;
    }
  }
  return l;
}
 
int main(){
  resheto();
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    ll x;
    cin >> x;
    ll sq = binsearch(x);
    if(sq*sq == x && primes[sq] == 1){
      cout << "YES" << '\n';
    } else{
      cout << "NO" << '\n';
    }
  }
}