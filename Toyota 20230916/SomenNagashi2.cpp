#include <bits/stdc++.h>
using namespace std;
struct person{
    long long id;
    long long leave_end;
    long long amount;
    person(long long id, long long leave_end, long long amount)
    : id(id), leave_end(leave_end), amount(amount){}
};

struct waitcompare{
    bool operator()(person const& a, person const& b) {
        return a.leave_end > b.leave_end;
    }
};

struct idcompare{
    bool operator()(person const& a, person const& b) {
        return a.id > b.id;
    }
};


int main()
{
    priority_queue<person, vector<person>, waitcompare> people_wait;
    priority_queue<person, vector<person>, idcompare> people_inline;

    long long N, M;
    cin >> N >> M;
    vector<person> pp(N + 1, {0, 0, 0});


    for (int n = 1; n <= N; n++){
        pp[n].id = n;
        people_inline.push(pp[n]);
    }

    for (int i = 1; i <= M; i++){
        long long T, W, S;
        cin >> T >> W >> S;
        while (!people_wait.empty()){
            person whowait = people_wait.top();
            if (whowait.leave_end <= T){
                people_wait.pop();
                people_inline.push(whowait);
            } else {
                break;
            }
        }
        if (!people_inline.empty())
        {
            person whoget = people_inline.top();
            whoget.amount += W;
            whoget.leave_end = T + S;
            pp[whoget.id] = whoget;
            people_inline.pop();
            people_wait.push(pp[whoget.id]);
        }
    }

    for (int j = 1; j <= N; j ++){
        cout << pp[j].amount << endl;
    }
	return 0;
}