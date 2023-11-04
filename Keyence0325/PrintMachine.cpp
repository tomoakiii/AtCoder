#include <bits/stdc++.h>
using namespace std;

/* Greedy Algorithm, 貪欲法 */

struct idcompare{
    bool operator()(pair<long long, long long> const& a, pair<long long, long long> const& b) {
        return a.second > b.second;
    }
};


int main()
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, idcompare> waitlist;

    long long N;
    cin >> N;
    vector<pair<long long, long long>> TD(N);
    long long T, D;
    for (int n = 0; n < N; n++){
        cin >> TD[n].first >> TD[n].second;
        TD[n].second += TD[n].first;
    }
    sort(TD.begin(), TD.end());
    long long cnt = 0;
    long long currentT = 0;
    long long countPrint = 0;
    do {
        if (waitlist.empty()){
            currentT = TD[cnt].first;
            waitlist.push(TD[cnt++]);
        }
        while(cnt < N){
            if (TD[cnt].first <= currentT){
                waitlist.push(TD[cnt++]);
            }else{
                break;
            }
        }
        pair<long long, long long> tmpTD = waitlist.top();
        waitlist.pop();
        if (tmpTD.second >= currentT){
            countPrint++;
            currentT++;
        }
    } while(!waitlist.empty() || cnt < N);

    cout << countPrint << endl;

	return 0;
}