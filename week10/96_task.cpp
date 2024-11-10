#include <bits/stdc++.h>
using namespace std;

const int N = 10e5+1;

int used[N];
vector<int> g[N];
vector<int> ans;
bool res;

void dfs(int v, vector<int>& a, int l){
    used[v] = 1;
    l++;
    for(int u : g[v]){
        
        if(!used[u]){
            a.push_back(u);
            dfs(u, a, l);
        }else{
            
                if(!res && used[u] == 1){
                    res = 1;
                    cout << "YES" << '\n';
                    int i = l-1;
                    vector<int> answer;
                    while(a[i] != u){
                        answer.push_back(a[i]);
                        i--;
                    }
                    answer.push_back(u);
                    reverse(begin(answer), end(answer));
                    for(int i : answer){
                        cout << i << " ";
                    }
                    
                }
            
        }
    }
    used[v] = 2;
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y);
    }
    int l = 0;
    for(int i = 1; i <= n; i++){
        vector<int> smth;
        if(!used[i]){
            smth.push_back(i);
            dfs(i, smth, l);
        }
    }
    if(!res){
        cout << "NO";
    }
    //cout << "1";
}