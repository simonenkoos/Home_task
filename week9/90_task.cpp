#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
using ll = long long;
const int N = 100000 + 1;
queue<int> q;
vector<int> a[N];
pair<int, int> visited[N];
map<int,vector<int>> level;
int ans = 0;
int level_max;

void dp(int number){
    if(number == 0){
        if(visited[1].second%2 == 1){
            ans = -1;
        }
        return;
    }
    for(auto& v : level[number - 1]){
        int cnt = 1;
        for(auto& u : a[v]){
            if(visited[u].first == number){
                if(visited[u].second % 2 == 0 && visited[u].second != 0){
                    ans++;
                    visited[u].second = 0;
                }else{
                    cnt += visited[u].second;
                }
            }
        }
        visited[v].second = cnt;
    }
    dp(number-1);
}

void bfs(){
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        for(int v : a[u]){
            if(visited[v].first == 0){
                visited[v].second = 1;
                visited[v].first = visited[u].first + 1;
                if(level_max < visited[v].first){
                    level_max = visited[v].first;
                }
                level[visited[v].first].push_back(v);
                q.push(v);
                bfs();
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0, x, y; i < n-1; i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    visited[1].first = 1;
    q.push(1);
    visited[1].second = 1;
    level[1].push_back(1);
    bfs();
    a[0].push_back(1);
    level[0].push_back(0);
    dp(level_max);
    cout << max(-1, ans-1);
}   