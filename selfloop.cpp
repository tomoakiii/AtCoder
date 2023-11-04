// cube rotation
// recursive loop
// 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
void clear(vector<vector<int>>);
vector<vector<int>> rotate(vector<vector<int>> P, int cnt);
void show(vector<vector<int>>);
void checkFill(vector<vector<int>>, vector<vector<int>>);
bool subroutine(vector<vector<int>>, vector<vector<vector<int>>>, int);
vector<vector<int>> offsetAdd(vector<vector<int>>, vector<vector<int>>, int, int);

int main(void) {
   vector<vector<vector<int>>> P(3);
   string tmpstr;
   int count = 0;
   for (int n = 0; n < 12; n++)
   {
       if (n % 4 == 0)
       {
           P[n / 4] = vector<vector<int>>(4);
       }
       P[n / 4][n % 4] = vector<int>(4);
       cin >> tmpstr;
       for (int m = 0; m < 4; m++)
       {
           if (tmpstr[m] == '#')
           { 
               P[n / 4][n % 4][m] = 1;
               count++;
           }
           else
           {
               P[n / 4][n % 4][m] = 0;
           }
       }
   }
   if (count != 16)
   {
       cout << "No";
       return 0;
   }

   vector<vector<int>> campus(10);
   for (int x = 0; x < 10; x++)
   {
       campus[x] = vector<int>(10);
   }
   if (subroutine(campus, P, 0))
   {
       cout << "Yes";
   }
   else
   {
       cout << "No";
   }

   return 0;
}

vector<vector<int>> offsetAdd(vector<vector<int>> campus, vector<vector<int>> a, int xoff, int yoff)
{
   for (int x = 0; x < a.size(); x++)
   {
       for (int y = 0; y < a[0].size(); y++)
       {
           campus[x + xoff][y + yoff] += a[x][y];
       }
   }
   return campus;
}

bool checkOK(vector<vector<int>> campus)
{
   for (int x = 0; x < campus.size(); x++)
   {
       for (int y = 0; y < campus[0].size(); y++)
       {
           if (campus[x][y] > 0 && (x <= 2 || x >= 7 || y <= 2 || y >= 7))
           {
               return false;
           }
           if (campus[x][y] > 1)
           {
               return false;
           }
       }
   }
   return true;
}


bool subroutine(vector<vector<int>> campus, vector <vector<vector<int>>> P, int ind)
{
   bool successFlag = false;
   for (int rot = 0; rot < 4; rot++)
   {
       if (ind == 0 && rot > 0)
       {
           break;
       }
       vector<vector<int>> tmp = rotate(P[ind], rot);
       for (int xoff = 0; xoff <= 6; xoff++)
       {
           for (int yoff = 0; yoff <= 6; yoff++)
           {
               vector<vector<int>> addRes = offsetAdd(campus, tmp, xoff, yoff);
               if (checkOK(addRes))
               {
                   if (ind < 2)
                   {
                       successFlag = subroutine(addRes, P, ind + 1);
                       if (successFlag)
                       {
                           // cout << ind << " " << rot << " " << xoff << " " << yoff << endl;
                           return true;
                       }
                   }
                   else
                   {
                       successFlag = true;
                       // cout << ind << " " << rot << " " << xoff << " " << yoff << endl;
                       return true;
                   }
               }
           }
       }
   }
   return false;
}


void clear(vector<vector<int>> campus)
{
   for (int n = 0; n < campus.size(); n++)
   {
       for (int m = 0; m < campus[n].size(); m++)
       {
           campus[n][m] = false;
       }
   }
}

vector<vector<int>> rotate(vector<vector<int>> P, int cnt)
{
   vector<vector<int>> tmpcampus(4);
   for (int n = 0; n < 4; n++)
   {
       tmpcampus[n] = vector<int>(4);
   }
   for (int n = 0; n < 4; n++)
   {
       for (int m = 0; m < 4; m++)
       {
           if (cnt == 0)
           {
               tmpcampus[n][m] = P[n][m];
           }
           if (cnt == 1)
           {
               tmpcampus[m][3 - n] = P[n][m];
           }
           if (cnt == 2)
           {
               tmpcampus[3 - n][3 - m] = P[n][m];
           }
           if (cnt == 3)
           {
               tmpcampus[3 - m][n] = P[n][m];
           }
       }
   }
   return tmpcampus;
}
