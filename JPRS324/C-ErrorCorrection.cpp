#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string T, S;
    cin >> N >> T;
    vector<int> out;
    for (int i=1; i<=N; i++){
        cin >> S;
        if (T == S){
            out.push_back(i);
        } else if (T.length() - S.length() == 0) {
            int ercnt = 0;
            for (int k=0; k<T.length(); k++){
                if (T[k] != S[k]){
                    ercnt++;
                    if (ercnt > 1){
                        break;
                    }
                }
            }
            if (ercnt <= 1){
                out.push_back(i);
            }
        } else if (T.length() - S.length() == 1){
            int ercnt = 0;
            int indT=0, indK=0;
            for (int k=0; k<T.length(); k++){
                if (T[indT++] != S[indK++]){
                    ercnt++;
                    indK--;
                    if (ercnt > 1){
                        break;
                    }
                }
            }
            if (ercnt <= 1){
                out.push_back(i);
            }
        } else if (T.length() - S.length() == -1){
            int ercnt = 0;
            int indT=0, indK=0;
            for (int k=0; k<S.length(); k++){
                if (T[indT++] != S[indK++]){
                    ercnt++;
                    indT--;
                    if (ercnt > 1){
                        break;
                    }
                }
            }
            if (ercnt <= 1){
                out.push_back(i);
            }
        }
    }
    cout << out.size() << endl;
    for (auto i : out){
        cout << i << " ";
    }

    return 0;
}