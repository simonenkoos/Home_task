#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int now_used, used;
int now_w, now_p;
ll ans;
void bt(int pos, int n, int limit, vector<pair<int, int>>& a){
    if(now_w > limit){
        return;
    }
    if(ans < now_p){
        ans = now_p;
        used = now_used;
    }
    if(ans == now_p){
        if(__builtin_popcount(used) > __builtin_popcount(now_used)){
            used = now_used;
        }
        if(__builtin_popcount(used) == __builtin_popcount(now_used)){
            if(used > now_used){
                used = now_used;
            }
        }
    }
    for(int i = pos; i < n; i++){
        now_w += a[i].first;
        now_p += a[i].second;
        now_used ^= (1 << i);
        bt(i + 1, n, limit, a);
        now_used ^= (1 << i);
        now_w -= a[i].first;
        now_p -= a[i].second;
    }
}
int main(){
    int n, limit;
    cin >> n >> limit;
    vector<pair<int, int>> a;
    a.push_back({0, 0});
    for(int i = 0, w, p; i < n; i++){  
        cin >> w >> p;
        a.push_back({w, p});
    }
    n++;
    bt(0, n, limit, a);
    cout << __builtin_popcount(used) << " " << ans;
    cout << '\n';
    int i = 0;
    while(used != 0){
        if(used & 1){
            cout << i << " ";
        }
        used /= 2;
        i++;
    }
}