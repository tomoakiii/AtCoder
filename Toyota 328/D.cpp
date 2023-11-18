#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    S = "D" + S + "DD";
    string out;
    vector<int> nextp(2e5+1, 0);
    vector<int> beforep(2e5+1, 0);
    
    
    for (int i = 0; i <= S.length(); i++){
        nextp[i] = i+1;
        beforep[i] = max(0, i-1);
    }

    int id=0;
    int p[5];
    while (true){
        p[0] = id; // before A
        p[1] = nextp[p[0]]; //A
        p[2] = nextp[p[1]]; //B
        p[3] = nextp[p[2]]; //C
        p[4] = nextp[p[3]]; // next to C 
        if (S[p[1]] == 'A' && S[p[2]] == 'B' && S[p[3]] == 'C'){
            nextp[id] = p[4];
            beforep[p[4]] = id;
            for (int i=0;i<3;i++){
                id = beforep[id];
            }

            continue;
        }
        id = p[1];
        if (p[4] >= S.length()-2){
            break;
        }
    }

    id = 0;
    while (nextp[id] < S.length()-2){
        cout << S[nextp[id]];
        id = nextp[id];
    }
    cout << endl;
    return 0;
}