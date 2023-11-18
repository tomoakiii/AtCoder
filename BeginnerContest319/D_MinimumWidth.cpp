#include <bits/stdc++.h>

using namespace std;

long long chk(long long width, auto &L){
    long long cnt=1, w=0;
    for (auto i : L){
        if (w + i <= width + 1){ // fit in line
            w += i;
        } else { // new line
            cnt++;
            w = i;
        }
    }
    return cnt;
}


int main(){
    int N, M;
    long long totall = 0;
    cin >> N >> M;
    long long minl = 1E10, maxl = 0;
    vector<long long> L(N);
    for (long long &ll : L){
        cin >> ll;
        ll++;
        minl = min(ll, minl);
        maxl = max(ll, maxl);
        totall += ll;
    }
    long long left = maxl-2, right = totall;
    while(left + 1 < right) {
        long long w = (left+right)/2;
        auto chkw = chk(w, L); // first is line, second is min width
        if (chkw <= M){
            right = w; // possible have more short answer.
        }
        else if (chkw > M){ // too many row
            left = w; // w cannot be answer
        }
    }
    cout << right << endl;
    return 0;
}