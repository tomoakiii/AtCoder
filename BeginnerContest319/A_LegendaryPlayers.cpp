#include <bits/stdc++.h>

using namespace std;

int main(){
    map<const string, unsigned int> dictionary;
    string s;
    dictionary["tourist"] = 3858;
    dictionary["ksun48"] = 3679;
    dictionary["Benq"] = 3658;
    dictionary["Um_nik"] = 3648;
    dictionary["apiad"] = 3638;
    dictionary["Stonefeang"] = 3630;
    dictionary["ecnerwala"] = 3613;
    dictionary["mnbvmar"] = 3555;
    dictionary["newbiedmy"] = 3516;
    dictionary["semiexp"] = 3481;  
    
    cin >> s;
    cout << dictionary[s] << endl;
    return 0;
}