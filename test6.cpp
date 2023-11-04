// Suffix
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
   int N, M;
   cin >> N >> M;
   string S, T;
   cin >> S;
   cin >> T;

   int init_flag = true;
   for (int n = 0; n < N; n++)
   {
       if (T[n] != S[n])
       {
           init_flag = false;
           break;
       }
   }

   int end_flag = true;
   int ind = 0;
   for (int n = M - N, ind = 0; n < M; n++, ind++)
   {
       if (T[n] != S[ind])
       {
           end_flag = false;
           break;
       }
   }

   int output = 3;
   if (init_flag && end_flag) output = 0;
   else if (init_flag) output = 1;
   else if (end_flag) output = 2; 
   cout << output;
   return 0;
}