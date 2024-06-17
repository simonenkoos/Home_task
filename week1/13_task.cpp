#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    map <pair<long long,long long>,long long> d;
    long long x, i=1;
    long long s = 0;
    long long tw = 0;
    while(n>0){
        cin >> x;
        if(d.count({i, x}) >= 1 && x!=i) s += d.count({i, x}); 
        if(x == i) {
            tw += 1; 
            if(d.count({x, i}) == 0) d[{x,i}] = 1;
            else d[{x,i}]++;
            s += tw - d.count({x,i});
        } 
        if(d.count({x, i}) == 0 && x!=i) d[{x, i}] = 1;
        else d[{x, i}]++;
        i++;
        n--;
    }
    cout << s;
}