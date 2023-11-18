#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, t, s=0;
    cin >> N >> X;
    for (int i=1; i<=N; i++){
        cin >> t;
        if (t <= X){
            s += t;
        }
    }

    cout << s << endl;
    return 0;
}