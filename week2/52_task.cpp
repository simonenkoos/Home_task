#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1000000+1;
int mindiv[N];
 
void resheto(){
  fill_n(mindiv, N, N);
  mindiv[1] = 1;
  for(int i=2; i<N; i++){
    if(mindiv[i] != N){
      continue;
    }
    mindiv[i] = i;
    for(ll j = (ll) i*i; j<N; j += i){
      mindiv[j] = min<int>(mindiv[j], i); 
    }
  }
}
int main(){
  resheto();
  int t;
  cin >> t;
  for(int i=0, n, k; i<t; i++){
    cin >> n >> k;
    cout << n + mindiv[n] + 2*(k-1)<< '\n';
  }
}