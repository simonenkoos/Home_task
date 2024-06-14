#include <iostream>
#include <vector>

using namespace std;

int bin1(int cur, int n, vector <int>& arr1){
    int right = n;
    int left = 0;
    int m;
    while(right > left + 1){
        m = (right + left)/2;
        if (arr1[m] <= cur) left = m;
        else right = m;
    }
    return right;
}

int main()
{
    int n,k,x,ans;
    cin >> n >> k;
    vector<int> arr1(n);
    int u = n;
    int h = k;
    int j = 0;
    while(n>0){
        cin >> x;
        arr1[j] = x;
        n--;
        j++;
    }
    int i = 0;
    while(i<k){
        cin >> x;
        if(x <= arr1[0]) ans = arr1[0];  
        else if(x >= arr1[u-1]) ans = arr1[u-1];
        else {
            ans = bin1(x,u,arr1);
            if(arr1[ans] - x >=  x - arr1[ans-1]) ans = arr1[ans-1];
            else ans = arr1[ans];
        }
        cout << ans << endl;
        i++;
    }
}