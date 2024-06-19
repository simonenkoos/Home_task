#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int k;
    k = 0;
    while ((k+1)*k < 2*n){
        k++;
    }
    cout << k;
}