#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define int long long

int max_n = 100000;
int a[4*100000];
int mx[4*100000];
int add[4*100000];

void build(int arr[], int v, int l, int r ){
    if (l == r){
        a[v] = arr[l];
        mx[v] = arr[l];
        add[v] = 0;
    }
    else{
        int m;
        m = (l+r)/2;
        build(arr, 2*v, l, m);
        build(arr, 2*v+1, m+1, r);
        a[v] = a[2*v] + a[2*v+1];
        mx[v] = max(mx[2*v], mx[2*v+1]);
        add[v] = 0;
    }
}
int find_sum(int v, int l, int r, int l_ans, int r_ans, int add1){
    //cout << l << r << '\n';
    if ( l_ans > r_ans){
        return 0;
    }
    if (l==l_ans && r == r_ans){
        return a[v] + add1*(r - l + 1);
    }
    else{
        int m = (l+r)/2;
        return find_sum(2*v, l, m, l_ans, min(r_ans, m), add1 + add[v]) + find_sum(2*v+1, m+1, r, max(l_ans, m+1), r_ans, add1 + add[v]);
    }
}
void change_value(int v, int l, int r, int pos, int value){
    if (l == r){
        a[v] = value;
        mx[v] = value;
    }
    else{
        int m;
        m = (l+r)/2;
        if (pos > m){
            change_value(2*v+1, m+1, r, pos, value);
        }
        else{
            change_value(2*v, l, m, pos, value);
        }
        a[v] = a[2*v] + a[2*v+1];
        mx[v] = max(mx[2*v], mx[2*v+1]);
    }
}
int find_max(int v, int l, int r, int l_ans, int r_ans, int add1){
    //cout << l << r << '\n';
    if ( l_ans > r_ans){
        return 0;
    }
    if (l==l_ans && r == r_ans){
        return mx[v]+add1;
    }
    else{
        int m = (l+r)/2;
        return max(find_max(2*v, l, m, l_ans, min(r_ans, m), add1 + add[v] ), find_max(2*v+1, m+1, r, max(l_ans, m+1), r_ans, add1+add[v]));
    }
}
void change_interval(int v, int l, int r,int l_ans, int r_ans, int value){
    if (l_ans > r_ans){
        return;
    }
    if (l == l_ans && r == r_ans){
        a[v] = a[v] + value*(r_ans - l_ans + 1);
        mx[v] = mx[v] + value;
        add[v] += value;
    }
    else{
        int m = (l+r)/2;
        change_interval(2*v, l, m, l_ans, min(r_ans, m), value);
        change_interval(2*v+1, m+1, r, max(l_ans, m+1), r_ans, value);
        a[v] = a[2*v] + a[2*v+1] + add[v]*(r - l + 1);
        mx[v] = max(mx[2*v], mx[2*v+1]) + add[v];
    }
}
signed main(){
    int n;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(arr, 1, 0, n-1);
    //for (int i = 0; i < 4*n; i++){cout << a[i] << " ";}
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        char a;
        cin >> a;
        if(a == 'm'){
            int l;
            int r;
            cin >> l;
            cin >> r;
            l = l-1;
            r = r-1;
            cout << find_max(1,0,n-1,l,r,0) << ' ';
        }
        else if(a == 'w'){
            int pos;
            int value;
            cin >> pos;
            cin >> value;
            pos = pos-1;
            change_value(1, 0, n-1, pos, value); 
        }
        else if(a == 'a'){
            int l;
            int r;
            int value;
            cin >> l >> r >> value;
            l = l-1;
            r = r-1;
            change_interval(1,0,n-1,l,r,value);
        }
    }
}