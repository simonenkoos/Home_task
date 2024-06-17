#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long bin_search(long long x, int n, vector<long long>& b){
  int left = 0;
  int right = n+1;
  int middle;
  while(right - left > 1){
    middle = (right + left)/2;
    if(b[middle] <= x) left = middle;
    else right = middle;
  }
  return left;
}
int main(){
  int n, q;
  cin >> n >> q;
  vector<long long> a(n+1);
  vector<long long> b(n+1);
  a[0] = 0;
  b[0] = 0; 
  for(int i=1; i<n+1; i++){
    cin >> b[i];  
  }
  sort(b.begin(),b.end());
  for(int i=1; i<n+1; i++){
    a[i] = a[i-1] + b[i]; 
  }
  long long x;
  long long ans;
  for(int i = 0; i < q; i++){
    cin >> x;
    long long j;
    j = bin_search( x, n, b);
    ans = (x * j - a[j]) + ((a[n]-a[j]) - x*(n-j));
    cout << ans << '\n';
  }
}