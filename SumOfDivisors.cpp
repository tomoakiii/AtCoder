#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<bool> isFactor(N + 1);
    vector<long long> f(N + 1);

    long long out = 0;
    for (long long n = 1; n <= N; n++){
        for (long long nn = 1; n * nn <= N; nn++){
                f[nn * n]++;
        }
        out += n * f[n];
        // cout << n << " " << f[n] << endl;
    }
    cout << out << endl;
    return 0;
}