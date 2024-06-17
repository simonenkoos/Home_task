#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
    int k, m, n;
    cin >> k >> m >> n;
    if (n<=k) cout << 2*m;
    
    else cout << m*((2*n-1)/k + 1);
}