#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    long long X, Y, Q;
    cin >> N >> X >> Y;
    long long total = 0;
    vector<pair<int, long long>> PT(N-1); 
    for (auto &pt : PT){
        cin >> pt.first >> pt.second;
    }

    vector<long long> bustime(840);
    for (int offs=0; offs<840; offs++){
        long long t = offs, rem;
        for (int i=0; i<N-1; i++){
            rem = t%PT[i].first;
            if (rem > 0){
                t += PT[i].first - rem;
            }
            t += PT[i].second;
        }
        t -= offs;
        bustime[offs] = t;
    }

    cin >> Q;
    vector<long long> ans(Q);
    for (long long qc=0; qc < Q; qc++ ){
        long long q;
        cin >> q;
        ans[qc] = q + bustime[(q+X)%840] + X + Y;
    }
    for (auto &a : ans ){
        cout << a << endl;
    }
    return 0;
}