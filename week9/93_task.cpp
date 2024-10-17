    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    using namespace std;
    using ll = long long;
    const int N = 200001;
    int ans;
    int visited[N];
    vector<int> a[N];
     
    void dfs(int v, int n){
        visited[v] = 1;
        int cnt = 0;
        for(int u : a[v]){
            cnt++;
            if(visited[u] == 0){
                dfs(u, n);
            }
        }
        if(cnt != 2){
            ans = 1;
        }
    }
     
    int main(){
        int n, m;
        cin >> n >> m;
        for(int i = 1, x, y; i <= m; i++){
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(visited[i] != 1){
                dfs(i, n);
                if(ans == 0){
                    cnt++;
                }
                ans = 0;
            }
        }
        cout << cnt;
    }   