#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int v, t;
    cin >> v >> t;
    cout << ((109+(v%109))*t)%109;
}