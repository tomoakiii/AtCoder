#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 2;
    string S = "ba";
    std::cin >> N >> S;
    for (int i = 0; i < N-1; i++){
        if ((S[i] == 'a' && S[i+1] == 'b') || (S[i] == 'b' && S[i+1] == 'a')){
            cout << "Yes" << endl;
            return 0;
        }
    }
    std::cout << "No" << endl;
    return 0;
    
}