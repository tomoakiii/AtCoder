#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    int N, Q;
    cin >> N >> Q >> S;
    vector<int> l(Q+1, 0);
    vector<int> r(Q+1, 0);

    for (int i=1; i<=Q; i++){
        cin >> l[i] >> r[i];
    }
    int ac=0;
    vector<int> acl(N+1, 0);
    for (int i=1; i<=N-1; i++){
        if(S[i]==S[i-1]){
            ac += 1;
        }
        acl[i] = ac;
    }
    
    for (int i=1; i<=Q; i++){
        cout << acl[r[i]-1] - acl[l[i]-1] << endl;
    }

    return 0;
}