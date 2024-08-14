#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
using ll = long long;
 
int main(){
  int a[11][11];
  a[0][0] = 1;
  a[1][1] = 1;
  a[1][0] = 1;
  for(int i=2; i<11; i++){
    a[i][0] = a[i][i] = 1;
    for(int j=1; j<i; j++){
      a[i][j] = a[i-1][j] + a[i-1][j-1];
    }
  }
  string s1, s2;
  cin >> s1 >> s2;
  int f1=0, z1=0, f2=0, z2=0, q2=0;
  for(int i=0; i<size(s1); i++){
    if(s1[i] == '+'){
       f1++;
     } else{
       z1++;
     }
    if(s2[i] == '+'){
      f2++;
    } else if(s2[i] == '-'){
      z2++;
    } else{
      q2++;
    }
  }
  f2 = f1-f2;
  z2 = z1-z2;
  if(f2 + z2 != q2 or f2<0 or z2<0){
    cout << 0;
  }
  else{
    int i = f2;
    float ans = float(a[q2][i])/float((1<<q2)); 
    cout << setprecision(10) << ans;
  }
}