
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
   int N;
   cin >> N;
   string tmpstr;
   cin >> tmpstr;
   for (int n = 0; n < N - 2; n++)
   {
       if (tmpstr[n] == 'A')
       {
           if (tmpstr[n + 1] == 'B')
           {
               if (tmpstr[n + 2] == 'C')
               {
                   cout << n + 1 << endl;
                   return 0;
               }
           }
       }
   }
   cout << -1 << endl;
   return 0;
}