#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == 0 && b == 0) cout << "INF";

    else if(a == 0)  cout << "NO";

    else if(c*(-b/a)+d == 0) cout << "NO";
    else{ 
        if(-(b%a) != 0) cout << "NO";
        else cout << -b/a;
    }
}