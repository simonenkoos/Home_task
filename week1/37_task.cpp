#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int bin_search(int x, int n, vector<int>& a){
  int left = 0;
  int right = n+1;
  int middle;
  while(right - left > 1){
    middle = (right + left)/2;
    if(a[middle] < x) left = middle;
    else right = middle;
  }
  return left;
}
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n+1);
  a[0] = 0;
  for(int i = 1; i<n+1; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans, x;
  for(int i = 0; i<q; i++){
    cin >> x;
    ans = bin_search(x,n,a);
    cout << n-ans << '\n';
  }
}