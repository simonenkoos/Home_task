#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double now_sum, sum, ans = 10e6, diff = 10e6;
void bt(int n, int pos, vector<double>& a){
    if(sum - now_sum < 0){
        diff = min(diff, - sum + now_sum);
        if(ans == 10e6){
            ans = min(-sum, diff);
        } else{
            ans = min(ans, diff);
        }
        return;
    }
    for(int i = pos; i < n-1; i++){
        int u = diff;
        now_sum += a[i];
        diff = abs(sum - now_sum);
        ans = min(diff, ans);
        bt(n, i+1, a);
        now_sum -= a[i];
        diff = u;
    }
}
int main(){
    int n;
    double x;
    cin >> n;
    vector<double> a;
    a.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
        sum += x;
    }
    sort(a.begin(), a.end());
    sum = sum/2 - a[n];
    bt(n+1, 0, a);
    cout << 2 * ans;
}