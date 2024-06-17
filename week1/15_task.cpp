#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int> left, const pair<string,int> right){
    return left.second < right.second;
}

int main()
{
    vector <pair<string,int>> d;
    int n;
    cin >> n;
    while(n>0){
        string s;
        int t;
        cin >> s >> t;
        d.push_back(make_pair(s,t));
        n--;
    }
    sort(rbegin(d),rend(d),compare);
    cout << d[1].first;
}