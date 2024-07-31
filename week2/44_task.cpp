#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
  if(!b){
    return a;
  } else{
    return gcd(b, a%b);
  }
} auto solve(int a, int b, int c, int d, ll gcd1){
    ll s, s1;
    s1 = (a * b * gcd1*gcd1);
    s = (a*gcd1 * (b*gcd1 - ((a*gcd1)/c) * d));
    ll gcd2 = gcd(s, s1);
    s = s/gcd2;
    s1 = s1/gcd2;
    cout << s << "/" << s1;
}
int main(){
  int a, b, c, d;
  ll gcd1, s=10e7, s1 = 1;
  cin >> a >> b >> c >> d;
  gcd1 = c*d / gcd(c, d);
  if(b*gcd1 - ((a*gcd1)/c) * d >= 0){
    solve(a, b, c, d, gcd1);
  }else{
    solve(b, a, d, c, gcd1);
  }
}