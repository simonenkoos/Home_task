#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int M = 100;
int a[M];
int used;
ll now_sum;
int ans = 100;
 
void bt(int n, int pos, int m){
    if(pos == m+1){
        return;
    }
    if(now_sum > n){
        return;
    }
    if(now_sum == n){
        if(used < ans){
            ans = used;
        }
        return;
    }
 
    bt(n, pos+1, m);
    used += 1;
    now_sum += a[pos];
    bt(n, pos+1, m);
    used += 1;
    now_sum += a[pos];
    bt(n, pos+1, m);
    now_sum -= 2*a[pos];
    used -= 2;
}
 
int main(){ 
    int n, m;
    cin >> n >> m;
    ll important_sum = 0;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        important_sum += 2*a[i];
    }
    bt(n, 0, m);
    if(important_sum < n){
        cout << -1;
    }
    else if(ans == 100){
        cout << 0;
    }
    else{
        cout << ans;
    }
}