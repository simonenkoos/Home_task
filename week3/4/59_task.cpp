#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
 
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << setprecision(7) << float((a*d))/float((a*d + c*b - a*c));
}