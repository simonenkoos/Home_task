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
    if(a[middle] <= x) left = middle;
    else right = middle;
  }
  return left;
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n+1);
  vector<int> b(n+1);
  a[0] = 0;
  b[0] = 0;
  int s, x1, x2, x3;
  for(int i = 1; i<n+1; i++){
    cin >> x1 >> x2 >> x3;
    a[i] = x1 + x2 + x3;
    b[i] = x1 + x2 + x3;
  }
  sort(a.begin(),a.end());
  int ans;
  for(int i = 1; i<n+1; i++){
    ans = n-bin_search(b[i] + 300,n,a);
    if(k > ans) cout << "Yes";
    else cout << "No";
    cout << '\n'; 
  }
}