#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, D, W;
    cin >> N >> D >> W;
    vector<pair<int, int>> TX(N);
    
    for (int i = 0; i < N; i++){
        cin >> TX[i].first;
        cin >> TX[i].second;
    }
    sort(TX.begin() + 1, TX.end());

    int maxout = 0;
    int Tstart = 0;
    int stind = 0;    
    for (int i = 0; i < N; i++){
        if (Tstart != TX[i].first){
            stind = i;         
        }
        Tstart = TX[i].first;
        for (int j = i; j < N; j++){
            if (Tstart + D <= TX[j].first){
                break;
            }
            
            if (TX[i].second - TX[j].second < W && TX[i].second - TX[j].second >= 0){
                int cnt = 0;
                int Xstart = TX[j].second;
                for (int k = stind; k < N; k++){
                    if (Tstart + D <= TX[k].first){
                        break;
                    }
                    if (Xstart + W > TX[k].second && Xstart <= TX[k].second ){
                        cnt++;
                    }
                }
                maxout = max(maxout, cnt);
            }
            
        }
    }
    cout << maxout << endl;
    return 0;
}