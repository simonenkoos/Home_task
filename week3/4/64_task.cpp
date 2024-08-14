#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
 
int main(){
  int n, t;
  double p;
  cin >> n >> p >> t;
  vector<vector<double>> q;
  q.resize(t+1);
  for(int i=t; i>=0; i--){
    for(int j=0; j<=n; j++){
      if(i == t){
        if(j == 0){
          q[i].push_back(1);
        } else{
          q[i].push_back(0);
        }
      } else{
        if(j == 0){
          q[i].push_back((1-p) * q[i+1][j]);
        } else{
          if(n == j){
            q[i].push_back(q[i+1][j-1] * p + q[i+1][j]);
          } else{
            q[i].push_back((1-p) * q[i+1][j] + p * q[i+1][j-1]);
          }
        }
      }
    }
  }
  double ans=0;
  for(int i=0; i<=n; i++){
    ans += q[0][i] * double(i);
  }
  cout << setprecision(7)<< ans;
}