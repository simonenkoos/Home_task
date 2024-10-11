#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const int N = 250;
pair<char, pair<int, int>> a[N][N];
int ans = 0;
queue<pair<int, int>> q;
int dr[4] = {-1, 0, 1, 0};
int dl[4] = { 0, 1, 0, -1};

void bfs(pair<int, int> v, int n){
    pair<int, int> u;
    while(q.size() > 0){
        v = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int r = dr[i] + v.first;
            int l = dl[i] + v.second;
            if(r >= 0 && l >= 0 && r < n && l < n && a[r][l].first != '+' && a[r][l].first != 'O'){
                if(a[r][l].first == '@'){
                    ans = 1;
                    a[r][l].second = v; 
                    break;
                }
                a[r][l].first = '+';
                u = pair<int, int> {r, l};
                a[r][l].second = v; 
                q.push(u); 
                
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    pair<int, int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j].first;
            if(a[i][j].first == 'X'){
                start = {i, j};
            }
            if(a[i][j].first == '@'){
                end = {i, j};
            }
        }
    }
    a[start.first][start.second].first = '+';
    q.push(start);
    bfs(start, n);
    pair<int, int> v;
    v = a[end.first][end.second].second;
    a[start.first][start.second].first = '!';
    if(ans == 1){
        cout << "Y" << '\n';
        while(start != v){
            a[v.first][v.second].first = '!';
            v = a[v.first][v.second].second;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j].first == '!'){
                    a[i][j].first = '+';
                }
                else if(a[i][j].first == '+'){
                    a[i][j].first = '.';
                }
                cout << a[i][j].first;
            }
            cout << '\n';
        }
    }
    else{
        cout << "N" << '\n';
    }
}   