#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int main(){
  double c;
  cin >> c;
  int n = 50;
  double right = c; 
  double left = 1;
  for(int i = 0; i<n; i++){
    double m = (right+left)/2;
    if(m*m + sqrt(m) >= c) right = m;
    else  left = m;
  }
  printf("%9f", right);
}