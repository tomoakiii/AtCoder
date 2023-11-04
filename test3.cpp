#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator> //for std::istream_iterator 
#include <algorithm>
using namespace std;
#define LONGMAX 0x0fffffff
int subroutine(long, int, int, vector <vector <int>>, long, vector<int>, int, char[]);

int main(void) {
   // cout << "program start";
   int N, M;
   cin >> N >> M;
   vector <vector <int>> Sarray;
   vector<int> reelStop(N);
   for (int i = 0; i < N; i++)
   {
       string tmpstr;
       cin >> tmpstr;
       vector <int> v(M);
       string singlestr;
       for (int j = 0; j < M; j++)
       {
           string s(1, tmpstr[j]);
           v[j] = stoi(s);
       }
       Sarray.push_back(v);
   }
   long min_result = LONGMAX;
   for (int n = 0; n <= 9; n++)
   {
       for (int i = 0; i < N; i++)
       {
           reelStop[i] = false;
       }
       char depthstring[255];
       depthstring[0] = 'A';
       depthstring[1] = '\0';

       long tmp_result = subroutine(min_result, N, M, Sarray, 0, reelStop, n, depthstring);
       if (min_result > tmp_result)
       {
           min_result = tmp_result;
       }
   }
   if (min_result >= LONGMAX - 1)
   {
       cout << -1;
       return 0;
   }
   else
   {
       cout << min_result;
   }
   return 0;
}

int subroutine(long min_result, int N, int M, vector <vector <int>> Sarray, long localtime, vector<int> reelStop, int n, char depthstring[])
{
   int found_flg = false;
   int non_found_cnt = 0;
   int success_end = false;
   vector<int> duplicate_flg(M);
   for (int i = 0; i < N; i++)
   {
       duplicate_flg[i] = false;
   }

   while (true)
   {
       int anyreelStop = false;
       int cnt_numbermatch = 0;
       vector<int> stop_reelnum(N);
       for (int i = 0; i < N; i++)
       {
           if (reelStop[i])
           {
               continue;
           }
           if (Sarray[i][(int)(localtime % (long)M)] == n)
           {
               stop_reelnum[cnt_numbermatch] = i;
               cnt_numbermatch++;
           }
       }

       if (cnt_numbermatch > 1)
       {
           non_found_cnt = 0;
           for (int i = 0; i < cnt_numbermatch; i++)
           {
               auto tmpreelStop = reelStop;
               tmpreelStop[stop_reelnum[i]] = true;
               localtime++;
               char newdepthstring[255];
               // ---- debug -----
               for (int k = 0; k < 255; k++)
               {
                   if (depthstring[k] == '\0')
                   {
                       newdepthstring[k] = 'A' + i;
                       newdepthstring[k + 1] = '\0';
                       break;
                   }
                   newdepthstring[k] = depthstring[k];
               }
               cout << newdepthstring << ", N=" << n << " TIME=" << localtime << " MIN=" << min_result << endl;
               for (int k = 0; k < N; k++)
               {
                   cout << tmpreelStop[k] << " ";
               }
               cout << endl;
               // ---- debug -----
               long tmp_result = subroutine(min_result, N, M, Sarray, localtime, tmpreelStop, n, newdepthstring);
               if (min_result > tmp_result)
               {
                   min_result = tmp_result;
               }
           }
           for (int i = 0; i < cnt_numbermatch; i++)
           {
               reelStop[stop_reelnum[i]] = true;
           }
       }
       else if (cnt_numbermatch == 1)
       {
           reelStop[stop_reelnum[0]] = true;
           non_found_cnt = 0;
           // ---- debug -----
           cout << depthstring << ", N=" << n << " TIME=" << localtime << endl;
           for (int k = 0; k < N; k++)
           {
               cout << reelStop[k] << " ";
           }
           cout << endl;
           // ---- debug -----

           if (std::all_of(reelStop.begin(), reelStop.end(), [](int b) {return b; }))
           {
               success_end = true;
           }
       }
       else if (cnt_numbermatch == 0)
       {
           non_found_cnt++;
           if (non_found_cnt > M)
           {
               break;
           }
       }
       if (success_end)
       {
           if (min_result > localtime)
           {
               min_result = localtime;
           }
           break;
       }
       localtime++;

   }
   return min_result;
}