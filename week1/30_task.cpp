#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int bin_search(int x,int n, vector<vector<long long>>& a){
  long long left = 0;
  long long right = n+1;
  while(right - left > 1){
    long long middle = (right + left)/2;
    if(a[middle][1] <= x) left = middle;
    else right = middle;
  }
  return left;
}
 
int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n, q;
    long long x;
    cin >> n >> q;
    vector<vector<long long>> a(n+1, vector<long long>(2)); //[i][0] - префиксная сумма, [i][1] - максимум на отрезке [0,i].
    a[0][0] = 0;
    a[0][1] = 0;
    for(int j = 1; j < n+1; j++){
      cin >> x;
      a[j][0] = a[j-1][0] + x;
      a[j][1] = max(x, a[j-1][1]);
    }
    for(int u = 0; u < q; u++){
      cin >> x;
      cout << a[bin_search(x,n, a)][0] << " ";
    }
    cout << '\n';
  }
}