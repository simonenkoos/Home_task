#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int h1, m1, s1;
    cin >> h1 >> m1 >> s1;
    int h2, m2, s2;
    cin >> h2 >> m2 >> s2;
    cout << (h2 - h1)*3600 + (m2 - m1)*60 + (s2 - s1);
}