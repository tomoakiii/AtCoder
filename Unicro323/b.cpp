#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    struct node{
        int win;
        int id;
    }; 
    auto comp = [](node &a, node &b){
        if (a.win == b.win){ return a.id > b.id; }
        else { return a.win < b.win; }
    }; // > (<) is smallest (largest) first
    priority_queue<node, vector<node>, decltype(comp)> pq(comp);
    for (int i =0; i<N; i++){
        string s;
        cin >> s;
        node n;
        n.id = i+1;
        n.win = 0;
        for (int j=0; j<N; j++){
            if (s[j]=='o'){
                n.win++;
            }
        }
        pq.push(n);
    }
    while (!pq.empty()){
        auto n=pq.top();
        cout << n.id << " ";
        pq.pop();
    }
    return 0;
}