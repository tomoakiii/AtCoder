#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<long long, long long> SC;

    for (int i =0; i<N; i++){
        int s, c;
        cin >> s >> c;
        SC[s] = c;
    }

    long long cnt=0, num, qty;
    auto itr = SC.begin();
    while (itr != SC.end()){
        num = (*itr).first;
        qty = (*itr).second;
        SC[2*num] += qty/2;
        cnt += qty%2;
        itr++;
    }
    cout << cnt << endl;

    return 0;
}