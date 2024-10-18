#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int N = 150001;
int ans;
vector<int> a[N];
int visited[N];
ll m_now, n_now;
ll cnt;

void dfs(int v){
    cnt = 0;
    visited[v] = 1;
    for(int u : a[v]){
        m_now++;
        if(visited[u] == 0){
            cnt++;
            n_now++;
            dfs(u);
        }
    }
    if(cnt != 1){
        ans = 1;
    }
}

int main(){
    int n;
    ll m;
    cin >> n >> m;
    for(int i = 1, x, y; i<=m; i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            dfs(i);
            if(not(n_now*(n_now+1) == m_now || ans == 0 || n_now == 1)){
                answer = 1;
            }
            m_now = 0;
            n_now = 0;
            ans = 0;
        }
    }
    if(answer == 1){
        cout << "NO";
    }else{
        cout << "YES";
    }
}   