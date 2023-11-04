// C-festival
#include <bits/stdc++.h>
using namespace std;
string dec2bin(long, int);
int costCalc(vector<int>, vector<vector<int>>, int, string);
#define LONGMAX 0x0fffffff

int main(void) {

   int N, K, P;
   cin >> N >> K >> P;
   vector<int> C(N);
   vector<vector<long>> A(N);
   vector<int> CsortInd(N);
   for (int n = 0; n < N; n++){
       A[n] = vector<long>(K);
       cin >> C[n];
       for (int k = 0; k < K; k++)
       {
           cin >> A[n][k];
       }
       CsortInd[n] = n;
   }

   for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
        if (C[i] > C[j]){
            int tmp = C[i];
            C[i] = C[j];
            C[j] = tmp;
            tmp = CsortInd[i];
            CsortInd[i] = CsortInd[j];
            CsortInd[j] = tmp;
        }
    }
   }
   vector<vector<long>> Asorted(N);
   for (int n = 0; n < N; n++){
    Asorted[n] = vector<long>(K);
    for(int k = 0; k < K; k++){
        Asorted[n][k] = A[CsortInd[n]][k];
    }
   }
   
    long cmin = LONGMAX;
    bool success = true;
    for (int i = 1; i < (1<<N); i++){
    long tmp_cmin = 0;
    vector<long> asum(K);
    for (int n = 0; n < N; n++){
        if ((i & (1<<n)) > 0){
            tmp_cmin += C[n];
            for (int k = 0; k < K; k++){
                asum[k] += Asorted[n][k];
            }
        }
    }
    success = true;
    for (int k = 0; k < K; k++){
        if (asum[k] < P){
            success = false;
            break;
        }
    }
    if (success)
    {
        cmin = tmp_cmin;
        break;
    }
   }

    if (success) cout << cmin << endl;
    else cout << -1 << endl;

   return 0;
}



