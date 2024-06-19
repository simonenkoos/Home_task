#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{
    long long n, s=0;
    cin >> n;
    int x;
    map<long long, long long> d;
    for(long long i = 0; i<n; i++){
        cin >> x;
        if(d.count(x)) {d[x]++; s += (d[x]-1); }
        else d[x] = 1;
    }
    cout << (n*(n-1))/2 - s; 
}