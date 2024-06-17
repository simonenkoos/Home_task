#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    cout << a*n + (b*n)/100 << " ";
    cout << (b*n)%100;
}