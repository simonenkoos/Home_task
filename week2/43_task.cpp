#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    if(!b) {
        return a;
    } return gcd(b, a%b);
}
int main()
{
    ll n, m, y = 0;
    cin >> n >> m;
    vector<ll> a(n);
    cin >> a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        y = gcd(abs(a[i] - a[i-1]), y);
    } for(ll i = 0, x; i < m; i++) {
        cin >> x;
        cout << gcd(y, a[0] + x) << " ";
    } 
}