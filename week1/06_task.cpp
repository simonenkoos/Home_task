#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int h, a, b;
    cin >> h >> a >> b;
    float c, d;
    c = (float) max((h-a-1),-1);
    d = c/(a-b);
    d = (int) floor(d);
    cout << (d + 1) + 1; 
}