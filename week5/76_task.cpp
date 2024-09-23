#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 10;
int C[N+1][N+1];
void precalc(){
    C[0][0] = 1;
    for(int i = 1; i < N+1; i++){
        for(int j = 0; j < i+1; j++){
            if(j == 0 || j == i){
                C[i][j] = 1;
                continue;
            }
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}
 
 
int a[N];
int mask[N];
int ans;
int n, k, m;
ll factorial(int a){
    if(a == 0){
        return 1;
    }
    return a * factorial(a-1);
}
 
void bt(int c, int u){
    if(u == n + 1){
        ans += C[k][c] * factorial(c);
        return;
    }
    for(int i = 1; i <= min(c + 1, k); i++){
        if((mask[i] & a[u]) == 0 && i < c + 1){
            mask[i] ^= (1 << (n - u));
            bt(c, u+1);
            mask[i] ^= (1 << (n - u));
        }
        if(i == c + 1){
            c++;
            mask[i] ^= (1 << (n - u));
            bt(c, u+1);
            c--;
            mask[i] ^= (1 << (n - u));
        }
    }
}
 
  
int main(){ 
    cin >> n >> k >> m;
    precalc();
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        a[u] ^= (1 << (n - v));
        a[v] ^= (1 << (n - u));    
    }
    mask[1] ^= (1 << (n-1));
    bt(1, 2);
    cout << ans;
}