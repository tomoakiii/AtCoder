#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
using namespace std;
using mint = atcoder::modint998244353;

int main(){
    int N, M;
    cin >> N >> M;
    long output;
    vector<pair<int,int>> card(N+1); 
    vector<double> exp(N+1, 0); 
    vector<pair<int,int>> flip; 
    
    for (int i=1; i<=N; i++){
        cin >> card[i].first;
        cin >> card[i].second;
        exp[i] = (double)card[i].first;
    }
    int x, y;
    


    for (int i=0; i<M; i++){
        if (x == y){
            exp[x] = (double)max(card[x].first, card[x].second);
        }
        else{
            exp[x] = ((double)card[x].first + (double)card[x].second)/2;
            exp[y] = ((double)card[y].first + (double)card[y].second)/2;
        }
    }

    cout << endl;
    return 0;
}