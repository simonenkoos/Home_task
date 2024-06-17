#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
long long pow1(long long a, long long c, long long b){
    if(b>1) return pow1(a, a*c, b-1);
    else if(b==1) return c;
    else return 1;
}

int main()
{
    vector <long long> n;
    long long count = 0;
    long long x, ans=0;
    long long i = 1;
    cin >> x;
    while(x > 0){
        if(x&1 == 1) {n.push_back(i); count++;}
        x = x/2;
        i++;
    }
    for(long long j=0; j<pow1( 2, 2, count); j++){
        ans = 0;
        long long count2 = j;
        for(long long k:n) {
            ans += pow1(2, 2, k-1)*(j%2);
            j = j/2;
        }
        j = count2;
        cout << ans << " ";
    }
}