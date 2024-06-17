#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long n, x;
    cin >> n;
    long long arr[200];
    for(int i=0; i<200; i++) arr[i] = 0;
    long long s = 0;
    while(n>0){
        cin >> x;
        arr[x%200]++;
        s += (arr[x%200]-1);
        n--;
    }
    cout << s;
}