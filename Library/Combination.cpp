#include <bits/stdc++.h>
using namespace std;
class combination{
public:
    long long N, R;
    vector<vector<long long>> comb = {};
    combination(long long n, long long r) : N(n), R(r){
        vector<bool> b(n, false);
        fill(b.end() - r, b.end(), true);
        do {
            vector<long long> c = {};
            for (long long i=0; i<n; i++) if (b[i]) c.push_back(i+1);
            comb.push_back(c);
        } while (std::next_permutation(b.begin(), b.end()));

    }
};