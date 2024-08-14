#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;
const int N=10;
int a[N];
ll sum;
int used;
 
void bt(int pos, int n, int k){
  if(pos == n){
    sum++;
    return;
  }
  for(int i=1; i<=n; i++){
    if((used >> i) & 1){
      continue;
    }
    if(pos != 0 && abs(i - a[pos-1]) > k){
      continue;
    }
    a[pos] = i;
    used ^= (1 << i);
    bt(pos + 1, n, k);
    a[pos] = 0;
    used ^= (1 << i);
  }
}
 
 
int main(){
  int n, k;
  cin >> n >> k;
  bt(0, n, k);
  cout << sum;
}