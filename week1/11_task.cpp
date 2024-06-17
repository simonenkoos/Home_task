#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long n, k, s=0, i=1;
    long long x;
    long long ans=0;
    cin >> n >> k;
    map<long long, long long> d; //префиксы
    d[0] = 1;
    while(n > 0){
        cin >> x;
        s += x;
        if(d.count(s-k) == 1) ans += d[s-k];
        if(d.count(s) == 1) d[s] += 1;
        else d[s] = 1;
        i += 1;
        n--;
    }
    cout << ans;
}