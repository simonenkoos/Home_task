#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int bin_search(int x, int n, vector<int>& a){ //приближенный бинпоиск
  int left = 0;
  int right = n+1;
  int middle;
  while(right - left > 1){
    middle = (right + left)/2;
    if(a[middle] > x) right = middle;
    else left = middle;
  }
  return min((a[right] - x), (x - a[left]));
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n+2);
  a[0] = -1000000000 * 2;
  a[n+1] = 1000000000 * 2;
  int x;
  for(int i = 1; i<n+1; i++){
    cin >> x;
    a[i] = x;
  }
  sort(begin(a),end(a));
  int ans = 1000000000 + 1;
  for(int j = 0; j<m; j++){
    cin >> x;
    if(ans > bin_search(x, n, a)) ans =  bin_search(x, n, a);
  }
  cout << ans;
}