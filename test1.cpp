#include <bits/stdc++.h>
using namespace std;

// カッコ列 S が整合しているかどうか
bool isvalid(const string &S) {
    int score = 0;
    for (auto c: S) {
        if (c == '(') ++score;
        else if (c == ')') --score;

        // 途中で 0 を下回るとダメ
        if (score < 0) return false;
    }
    
    // 最後に 0 なら true、そうでなければ false
    return (score == 0);
}

int main() {
    // 入力
    int N;
    cin >> N;

    // カッコ列を順に列挙していく
    // 1 << N means 2^N
    for (int bit = 0; bit < (1<<N); ++bit) {
        string S = "";

        // 最上位の桁から順に見ていく
        for (int i = N - 1; i >= 0; --i) {
            cout << (1<<i) << " " << (bit & (1<<i)) << endl;
            if (!(bit & (1<<i))) S += "(";
            else S += ")";
        }

        // 整合していたら出力
        if (isvalid(S)) cout << S << endl;
    }
} 