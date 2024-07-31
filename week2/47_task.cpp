#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int gcd(int a, int b){
  if(!b){
    return a;
  } return gcd(b, a%b);
}
map<int, int> a;
int main(){
  int n;
  vector<int> b, keys;
  cin >> n;
  for(int i=0, x; i<n*n; i++){
    cin >> x;
    a[x] += 1;
    keys.push_back(x);
  }sort(keys.rbegin(),keys.rend());
  for(int i : keys){
    if(a[i]<=0){
      continue;
    } b.push_back(i);
    cout << i << " ";
    for(int j : b){
      a[gcd(j, i)] -= 2;
    }
  }
}