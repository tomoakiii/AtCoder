#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
/* string operation */


vector<char> func(vector<char> S, int K){
    vector<char> out;
    bool isf = false;
    for (int n = S.size() - 1; n >= 1; n--){
        if (S[n-1] == 'o' && S[n] == 'f'){
            isf = true;
            int minlen = S.size();
            for (int ind = min(n + K, (int)S.size() - 1); ind >= n; ind--){
                vector<char> tmpS(S);
                tmpS.erase(tmpS.begin() + n-1, tmpS.begin() + ind + 1);
                tmpS = func(tmpS, K);
                if (minlen > tmpS.size()){
                    minlen = tmpS.size();
                    out = tmpS;
                }
            }
            break;
        }
    }
    if (!isf) {return S;}
    else {return out;}
}


int main()
{
    string S;
    int K;
    cin >> S >> K;
    vector<char> Sarray(S.length());
    for (int n = 0; n < S.length(); n++){
        Sarray[n] = S[n];
    }
    Sarray = func(Sarray, K);
    cout << Sarray.size() << endl;
    return 0;
}