#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if(b<6*a+1 && b>a-1) cout << "Yes";
    else cout << "No"; 
}