#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> chk(long long width, auto &L){
    long long cnt=1, w=0, maxw = 0;
    for (auto i : L){
        if (w + i <= width + 1){ // fit in line
            w += i;
        } else { // new line
            cnt++;
            maxw = max(maxw, w);
            w = i;
        }
    }
    maxw = max(maxw, w);
    return {cnt, maxw-1};
}


int main(){
    int N, M;
    long long totall = 0;
    cin >> N >> M;
    long long maxl = 0, minl = 1E10;
    vector<long long> L(N);
    vector<vector<long long>> lines(M);
    for (long long &ll : L){
        cin >> ll;
        ll++;
        maxl = max(ll, maxl);
        minl = min(ll, minl);
        totall += ll;
    }
    long long left = totall / M, right = totall;
    map<long long, long long> wid_line;
    while(true) {
        long long w = (left+right)/2;
        auto chkw = chk(w, L); // first is line, second is min width
        wid_line[w] = chkw.first;
        wid_line[chkw.second] = chkw.first;    
        if (chkw.first == M){
            if (wid_line.count(chkw.second-1)==1){
                if (wid_line[chkw.second-1] + 1 == chkw.first){
                    cout << chkw.second << endl;
                    break;
                }
            }
            right = chkw.second - minl; // possible have more short answer.
        }
        else if (chkw.first > M){ // too many row
            if (wid_line.count(w + 1) == 1){
                if (wid_line[w+1] == M){
                    cout << w+1 << endl;
                    break;
                }
            }
            left = w + minl; // need more width
        } else { // row margin remain
            right = chkw.second - 1;
        }
        if (left >= right){
            cout << right << endl;
            break;
        }
    }
    return 0;
}