#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, d, s=0;
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> d;
        if (i>=10 && i%10 != i/10){
            continue;
        }
        int v = i%10;
        if (d >= v*10 + v){
            s+=2;
        } else if (d >= v){
            s++;
        }
    }

    cout << s << endl;
    return 0;
}