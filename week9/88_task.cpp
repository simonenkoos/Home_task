#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int N = 101;
pair<int, int> visited[N];
int ans = 0;
int a[N][N];


void dfs(int v, int n){
    visited[v].first = 1;
    for(int i = 1; i <= n; i++){
        if(a[v][i] == 1){
            if(visited[i].first == 1){
                if((visited[v].second + 1)%2 != visited[i].second){
                    ans = 1;
                }
            }else{
                visited[i].second = (visited[v].second + 1)%2;
                dfs(i, n);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(visited[i].first == 0){
            dfs(i, n);
        }
    }
    
    if(ans == 1){
        cout << "NO";
    }else{
        cout << "YES";
    }
}   