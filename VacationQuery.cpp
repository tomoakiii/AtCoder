#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, Q, L, R;
    string S;
    int c;
    cin >> N >> Q >> S;
    long long count1[N + 1];
    count1[0] = 0;
    int ind = 0, last = 0;
    if (S[0] == '0'){
        count1[ind]--;
        last = 0;
    }
    else{
        count1[ind]++;
        last = 1;
    }
    for (int i = 1; i < N; i++){
        if (S[i] = '1'){
            if (last == 0){
                ind++;
            }
            count1[ind]++;
            last = 1;
        }else{
            if (last == 1){
                ind++;
            }
            count1[ind]--;
            last = 0;
        }
    }

    for (int n = 1; n <= Q; n++)
    {
        cin >> c >> L >> R;
        if (c == 1){
            long long sumL = 0;
            long long firstcnt = 0;
            for (int i = 0; i < N; i++){
                sumL += abs(count1[i]);
                if (sumL >= L){
                    if (count1[i] > 0){
                        firstcnt = count1[i] - L;
                    }
                    break;
                }
            }


            for (int i = L; i <= R; i++){
                S[i] =  (S[i] == '1') ? '0' : '1';
                count1[i] = (S[i] == '1') ? (count1[i-1] + 1) : 0;
            }
        }
        if (c == 2){
            for (int i = L; i <= R; i++){
                if (S[i] == '0'){
                    break;
                }else{
                    count1[i] = count1[i] - count1[L] + 1;
                }
           }
            int tMax = 0;
            for (int i = L; i <= R; i++){
                tMax = max((long long)tMax, count1[i]);
            }
            cout << tMax << endl;
        }
    }
	return 0;
}