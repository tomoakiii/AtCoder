#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int p1, tmp, pmax=0;
    cin >> p1;
    for (int i=2; i<=N; i++){
        cin >> tmp;
        pmax = max(tmp, pmax);
    }
    cout << max(pmax - p1 + 1, 0) << endl;

    return 0;
}