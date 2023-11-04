// C-festival
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int N, M;
   cin >> N >> M;
   vector <int> A(M);
   int a;
   for (int n = 0; n < M; n++)
   {
       cin >> a;
       A[n] = a - 1;
   }
   int lastday = -1;
   vector <int> I(N);
   for (int n = 0; n < M; n++)
   {
       I[A[n]] = 0;
       for (int k = lastday + 1; k < A[n]; k++)
       {
           I[k] = A[n] - k;
       }
       lastday = A[n];
   }
   for (int n = 0; n < N; n++)
   {
       cout << I[n] << endl;
   }
   return 0;
}