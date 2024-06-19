#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    int x, s=0;
    for(int i=0; i<n; i++){
        cin >> x;
        if(a[x] == 0) {a[x]++; s++;}
        else if (a[x] == 1) s = n+1;
    }
    if(s == n) cout << "Yes";
    else cout << "No";
}