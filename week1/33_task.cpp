#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
bool check(int middle, int s, int n, vector<int>& a){
  int i = middle;
  for(i; i<n+1; i++){
    if(a[i] - a[i-middle] <= s) return true;
  }
  return false;
}
 
int bin_search(int s, int n, vector<int>& a){
  int left = 0;
  int right = n+1;
  int middle;
  while(right - left > 1){
    middle = (right + left)/2;
    if(check(middle, s, n, a) == true) left = middle;
    else right = middle;
  }
  return left;
}
int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n, s;
    cin >> n >> s;
    vector<int> a(n+1);
    a[0] = 0;
    int x;
    for(int j = 1; j<n+1; j++){
      cin >> x;
      a[j] = a[j-1] + x;
    }
    if(a[n] < s) cout << -1;
    else cout << n - bin_search(s, n, a);
    cout << '\n';
  }
}