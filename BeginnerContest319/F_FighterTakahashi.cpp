#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    struct node{
        int p;
        int t;
        int n;
        long s;
        long g;
    };

    vector<vector<node>> field(N);
    auto comp = [](node &a, node &b){return a.s > a.s;}; // > (<) is smallest (largest) first
    priority_queue<node, vector<node>, decltype(comp)> enermyque(comp);
    auto comp2 = [](node &a, node &b){return a.g > a.g;}; // > (<) is smallest (largest) first
    priority_queue<node, vector<node>, decltype(comp2)> dragque(comp2);

    for (int n=2; n<N; n++){
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
            dragque.push(nd);
        }
    }
    long long currs = 1;
    while (true){
        if (!enermyque.empty()){
            auto tp = enermyque.top();
            if (tp.s <= currs){
                enermyque.pop();
                currs += tp.s;
                for (auto nd : field[tp.n]){
                    if (nd.t == 1){
                        enermyque.push(nd);
                    } else {
                        dragque.push(nd);
                    }
                }
                continue;
            }
        }
        if (!dragque.empty()){
            auto tp = dragque.top();
            dragque.pop();
            currs *= tp.g;
            for (auto nd : field[tp.n]){
                if (nd.t == 1){
                    enermyque.push(nd);
                } else {
                    dragque.push(nd);
                }
            }
            continue;
        }
        break;
    }
    if (!enermyque.empty()){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}