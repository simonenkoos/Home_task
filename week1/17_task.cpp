#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b(n);
    a[0] = 0;
    int x;
    for(int i = 1; i < n+1; i++){
        cin >> x;
        a[x]++;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    long ans=0;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans += a[b[x-1]];
    }
    cout << ans;
}