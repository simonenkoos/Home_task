#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans=0, ost=0, ans_ost=0;
    ans = n/60*440;
    ost = n - n/60*60;

    int type60=0, type10=0, type1=0;
    type60 = n/60;

    if(ost > 40) {ans += 440; type60 += 1;}
    else {
        ans_ost += ost/10*125;
        type10 = ost/10;
        ost = ost - ost/10*10;

        if(ost > 8) {ans_ost += 125; type10 += 1;}
        else{
            ans_ost += ost*15;
            type1 = ost;
        }
        if(ans_ost > 440) {ans += 440; type1 = 0; type10 = 0; type60 += 1;}
        else ans += ans_ost;
    }
    cout << type1 << " " << type10 << " " << type60;
}