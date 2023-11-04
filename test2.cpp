#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int N, i, j;
   cin >> N;
   vector <pair<int, int>> myvectp;
   pair<int, int> tmpp;
   for (i = 0; i < N; i++)
   {
       cin >> tmpp.first >> tmpp.second;
       myvectp.push_back(tmpp);
   }

   for (i = 0; i < N; i++)
   {
       for (j = i + 1; j < N; j++)
       {
           if (myvectp[i].second > myvectp[j].second)
           {
               swap(myvectp[i], myvectp[j]);
           }
       }
   }

   for (i = 0; i < N; i++)
   {
       cout << myvectp[i].first << " " << myvectp[i].second << endl;
   }
   return 0;
}