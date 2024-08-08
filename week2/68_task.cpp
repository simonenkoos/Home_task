#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
int bpow(int a, int b){
  if(!b){
    return 1;
  } if(b & 1){
    return a*bpow(a, b-1);
  } return bpow(a*a, b/2);
}

int main(){
  int n, x;
  cin >> n >> x;
  int cnt = 12 - n;
  ll j = bpow(10, cnt)*x;
  cout << j << " ";
  while(j < bpow(10, cnt+1)*x ){
    int q=j;
    for(int i=2; i*i<=q; i++){
      while(q%i == 0){
        q /= i;
      }
    }
    if( q == j){
      cout << q + x*(cnt-1);
      j = bpow(10,cnt+1);
    }
    j += 2;
  }
}