#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool check(int x, int n, vector<vector<double>>& a){
  double t1 = a[x][2];
  double t2 = a[n][2] - a[x][2];
  if(t1 > t2 && t2 + (a[x][0] - a[x-1][0])/(a[x][1]) >= t1) return true;
  if(t1 + (a[x][0] - a[x-1][0])/(a[x][1]) >= t2) return true;
  return false;
}

int main(){
  int n;
  cin >> n;
  vector<vector<double>> a(n+1, vector<double>(3));
  double x;
  a[0][0] = 0;
  a[0][1] = 0;
  a[0][2] = 0;
  for(int i = 1; i < n+1; i++){
    cin >> x;//длина
    a[i][0] = x + a[i-1][0];
    cin >> a[i][1];//скорость
    a[i][2] = a[i-1][2] + a[i][0]/a[i][1];//время
  }
  int right = n+1;
  int left = 1;
  int middle;
  cout << check(2,n,a);
  while(right - left > 1){
    middle = (right + left)/2;
    if(check(middle, n, a) == true) left = middle;
    else  right = middle;
    //cout << middle << "$ " << right << " "<< left << "% ";
  }
  cout << left;
}