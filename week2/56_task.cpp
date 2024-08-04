#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int euclid(int a, int b, int& x, int& y){
  if(!b){
    x = 1;
    y = 0;
    return a;
  }
  int x0, y0;
  int res = euclid(b, a%b, x0, y0);
  x = y0;
  y = x0 - y0*(a/b);
  return res;
}
int main(){
  int a, b, c, x, y, d;
  cin >> a >> b >> c;
  c = -c;
  d = euclid(a, b, x, y);
  if(c%d == 0){
    cout << (ll)x*(c/d) << " " << (ll)y*(c/d);
  } else{
    cout << -1;
  }
}