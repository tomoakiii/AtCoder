#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

long long gcd_arr(vector<long long> &a){
  int n = a.size();
  for(int i=n-2; i>=0; i--){
    a[i] = gcd(a[i], a[i+1]);
  }
  return a.front();
}


int main(){
    vector<long long> T(3);
    T = {7, 14, 21};
    auto TG = T;
    long long gcd = gcd_arr(TG);
    cout << gcd << endl;
    return 0;
}

