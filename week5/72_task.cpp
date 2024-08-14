#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;
const int N=10;
int a[N];
int point; 
ll sum;
int used;
 
void bt(int pos, int n, int k){
  if(pos == n){
    if(point == k){
      sum++;
    }
    return;
  }
  for(int i=1; i<=n; i++){
    if(((used >> i) & 1) or (point > k)){
      continue;
    }
    int q = point;
    if(pos+1 == i){
      point++;
    }
    a[pos] = i;
    used ^= (1 << i);
    bt(pos + 1, n, k);
    point = q;
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