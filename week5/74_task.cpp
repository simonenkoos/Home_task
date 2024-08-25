#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int now_used, used;
int now_s, s;
ll now_w, now_p;
ll ans;
void bt(int pos, int n, int limit, vector<pair<int, int>>& a){
    if(now_w > limit){
        return;
    }
    if(ans < now_p){
        ans = now_p;
        used = now_used;
        s = now_s;
    }
    if(ans == now_p){
        if(__builtin_popcount(used) > __builtin_popcount(now_used)){
            used = now_used;
            s = now_s;
        }
        if(__builtin_popcount(used) == __builtin_popcount(now_used)){
            if(s < now_s){
                s = now_s;
                used = now_used;
            }
        }
    }
    for(int i = pos; i < n; i++){
        now_w += a[i].first;
        now_p += a[i].second;
        now_used ^= (1 << i);
        now_s ^= (1 << (n-i));
        bt(i + 1, n, limit, a);
        now_s ^= (1 << (n-i));
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
    int bp = __builtin_popcount(used);
    int i = 0;
    cout << __builtin_popcount(used) << " " << ans;
    cout << '\n';
    while(used != 0){
        if(used & 1){
            cout << i << " ";
        }
        used /= 2;
        i++;
    }
}