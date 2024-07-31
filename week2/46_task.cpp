#include <iostream>
using namespace std;
using ll = long long;
ll gcd(int a, int b){
  if(!b){
    return a;
  } return gcd(b, a%b);
}
int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int b, d;
    cin >> b >> d;
    cout << ((b-1)*gcd(b, d))/d <<'\n';
  }
}