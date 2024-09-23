#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 40;
int a[N];
void bt(int n, int i, int pos){
    if(n < 0){
        return;
    }
    if(n == 0){
        if(a[1] == 0){
            return;
        }
        for(int j = 0; j < pos - 1; j++){
              cout << a[j] << "+";
        }
        cout << a[pos - 1];
        cout << '\n';
        return;
    }
    for(int j = i; j <= n; j++){
        a[pos] = j;
        bt(n - j, j, pos + 1);
        a[pos] = 0;
    }
}
int main(){
    int n;
    cin >> n;
    bt(n, 1, 0);
}