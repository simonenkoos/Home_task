#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool check(int distance, int n, int k, vector<int>& coordinates){
    int x0 = coordinates[0];
    int count = 1;
    for(int i=0; i < n; i++){
        if(coordinates[i] - x0 >= distance){
            count++;
            x0 = coordinates[i];
        }
    }
    if(count >= k) return true;
    return false;
}


int main(){
  int n, k;
  cin >> n >> k;
  int x;
  vector<int> coordinates(n);
  for(int i=0; i<n; i++){
      cin >> x;
      coordinates[i] = x;
  }
  int right = coordinates[n-1] - coordinates[0] + 1;
  int left = 0;
  while(right - left > 1){
    int m = (right + left)/2;
      if(check(m,n,k,coordinates) == true) left = m;
      else  right = m;
  }
  cout << left;
}