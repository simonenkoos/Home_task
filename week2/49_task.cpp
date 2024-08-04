#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 200000;
vector<ll> primes;
int np[N];
void resheto(){
  fill_n(np, N, 0);
  for(ll i=2; i<N; i++){
    if(np[i] == 1){
      continue;
    }
    primes.push_back(i);
    for(ll j=i*i; j < N; j += i){
      np[j] = 1;
    }
  }
}
int bin_search(vector<ll>& primes, int a){
  ll r = primes.size();
  ll l = -1;
  while(r - l > 1){
    ll m = (r+l) / 2;
    if(primes[m] >= a){
      r = m;
    } else{ 
      l = m;
    }
  }
  return r;
}
int main(){
  resheto();
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int d, d1, d2;
    cin >> d;
    d1 = bin_search(primes, 1+d);
    d2 = bin_search(primes, primes[d1]+d);
    cout << (ll)primes[d1]*primes[d2] << "\n";
  }
}