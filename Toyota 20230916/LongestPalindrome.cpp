#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int len = 1;
    for (int n=0; n < (int)S.length() - 2; n++)
    {
        if (S[n] == S[n+1]){
            int tmpLen = 2;
            for (int nn=1; nn <= std::min(n, (int)S.length()-n-1); nn++){
                if (S[n-nn] == S[n+1+nn]){
                    tmpLen+=2;
                }else{
                    break;
                }
            }
            len = std::max(len, tmpLen);
        }

        if (S[n] == S[n+2]){
            int tmpLen = 3;
            for (int nn=1; nn <= std::min(n, (int)S.length()-n-2); nn++){
                if (S[n-nn] == S[n+2+nn]){
                    tmpLen+=2;
                }else{
                    break;
                }
            }
            len = std::max(len, tmpLen);
        }
    }
    cout << len << endl;
	return 0;
}