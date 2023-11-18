#include <bits/stdc++.h>

using namespace std;

int main(){
    int search[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
//    int search[] = { 7, 8, 5, 0, 4, 6, 2, 1, 3 };
    int arr[9];
    for (auto &a : arr){
        cin >> a;
    }
    double falcnt = 0, allcnt = 0;;
    do {
        vector<int> c(9, 0);
        bool flg = true;
		for (int i : search){
            int x = i%3;
            int y = (i-x)/3;
            vector<int> chk;
            for (int rx = 0; rx < 3; rx++){
                if (c[3*y + rx] != 0){
                    chk.push_back(c[3*y + rx]);
                }
            }
            if (chk.size() > 1 && chk[0] == chk[1]){
                flg = false;
                break;
            }
            chk.clear();
            for (int ry = 0; ry < 3; ry++){
                if (c[3*ry + x] != 0){
                    chk.push_back(c[3*ry + x]);
                }
            }
            if (chk.size() > 1 && chk[0] == chk[1]){
                flg = false;
                break;
            }
            chk.clear();
            for (int t = 0; t < 9; t+=4){
                if (c[t] != 0){
                    chk.push_back(c[t]);
                }
            }
            if (chk.size() == 2 && chk[0] == chk[1]){
                flg = false;
                break;
            }
            chk.clear();
            for (int t = 2; t < 7; t+=2){
                if (c[t] != 0){
                    chk.push_back(c[t]);
                }
            }
            if (chk.size() == 2 && chk[0] == chk[1]){
                flg = false;
                break;
            }
            c[i] = arr[i];
        }
        if (flg){
            falcnt++;
        }
        allcnt++;
	} while (next_permutation(search, search + 9));
    std::cout << std::setprecision(24) << falcnt/allcnt << endl;
    return 0;
}