#include <bits/stdc++.h>

using namespace std;

struct node{
    int p=0;
    int t=0;
    int n=0;
    long s=0;
    long g=0;
    bool used = false;
};
int N;
vector<vector<node>> field;

bool explorer(long long currs, auto drglist, auto enermyque, int drgind, int open){
    if (drgind > -1){
        cout << "#" << drglist[drgind].n << " ";
            
        drglist[drgind].used = true;
        open++;
        currs *= drglist[drgind].g;
        for (auto &nd : field[drglist[drgind].n]){
            if (nd.t == 1){
                enermyque.push(nd);
            } else {
                drglist.push_back(nd);
            }
        }
    }
    
    while (!enermyque.empty()){
        auto tp = enermyque.top();
        if (tp.s <= currs){
            enermyque.pop();
            open++;
            cout << tp.n << " ";
            currs += tp.s;
            for (auto &nd : field[tp.n]){
                if (nd.t == 1){
                    enermyque.push(nd);
                } else {
                    drglist.push_back(nd);
                }
            }
        } else {
            break;
        }
    }
    if (open == N){
        return true;
    }
    
    for (int i = 0 ; i < drglist.size(); i++){
        auto tp = drglist[i];
        if (!tp.used){
            if (explorer(currs, drglist, enermyque, i, open)){
                return true;
            }
        }
    }
    
    cout << " LOOSE" << endl;
    return false;
 }


int main(){

    cin >> N;

    field.resize(N);
    auto comp = [](node &a, node &b){return a.s > a.s;}; // > (<) is smallest (largest) first
    priority_queue<node, vector<node>, decltype(comp)> enermyque(comp);
    vector<node> drglist;

    for (int n=2; n<=N; n++){
        node nd;
        cin >> nd.p >> nd.t >> nd.s >> nd.g;
        nd.n = n;
        field[nd.p].push_back(nd);
    }
    
    int cnd = 0;
    for (auto nd : field[1]){
        if (nd.t == 1){
            enermyque.push(nd);
        } else {
            drglist.push_back(nd);
        }
    }
    

   if (explorer(1, drglist, enermyque, -1, 1)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}