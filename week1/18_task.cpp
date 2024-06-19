#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    long long a1, b1, ans=k;
    vector<vector<long long>> a(n+1,vector<long long>(2));
    a[0][0] = 0;
    a[0][1] = 0;
    for(long long i = 1; i<n+1; i++){
        cin >> a1 >> b1;
        a[i][0] = a1;
        a[i][1] = b1; 
    }
    sort(a.begin(),a.end());
    long long i = 1;
    while(k>-1 && i<n+1){
        k -= (a[i][0]-a[i-1][0]);
        if(k>-1) {k+= a[i][1]; ans += a[i][1];}
        i++;
    }
    cout << ans;
}