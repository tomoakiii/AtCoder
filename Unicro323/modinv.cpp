#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;


long long pow(long long a, long long n){
    long long ret=1;
    for(; n>0; n>>=1, a=a*a % MOD ){
        if(n % 2 == 1){
            ret = ret * a % MOD;
        }
    }
    return ret;
}

long long modinv(long long a){
    return pow(a, MOD - 2);
}


int main(){
    for (int i=1; i<=99; i++){
        cout << 7*i << " ";
    }
    return 0;
}

