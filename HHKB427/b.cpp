#include <bits/stdc++.h>
//#include<iostream>
using namespace std;

int main(){
    long long B;
    cin >> B;
    for (long long i = 1; i <= 18; i++){
        long long tmp = 1;
        for (long long k = 1; k <= i; k++){
            tmp *= i;
        }
        if (tmp == B){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
    
}