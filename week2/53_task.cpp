#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
const int mod = 1000000007;
const int N = 200000+1;
int sum(int a, int b){
  return (a += b) > mod ? a-mod : a;
}
int diff(int a, int b){
  return (a -= b) < 0 ? a+mod : a; 
}
int mult(int a, int b){
  return (ll)a*b % mod;
}
int bpow(int a, int b){
  if(!b){
    return 1;
  }
  if(b & 1){
    return mult(a, bpow(a, b-1));
  }
  return bpow(mult(a, a), b >> 1);
}
int inv(int a){
  return bpow(a, mod-2);
}
int fact[N];
int ifact[N];
void prepare(){
  fact[0] = 1;
  for(int i = 1; i<N; i++){
    fact[i] = mult(fact[i-1], i);
  }
  ifact[N-1] = inv(fact[N-1]);
  for(int i = N-2; i>=0; i--){
    ifact[i] = mult(i+1, ifact[i+1]);
  }
}
int C(int k, int n){
  return mult(fact[n], mult(ifact[k], ifact[n-k]));
}
int main(){
  int n;
  cin >> n;
  prepare();
  cout << diff(mult(2,C(diff(n,1), diff(mult(2,n),1))),n);
}