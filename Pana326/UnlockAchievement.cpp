// LUOGU_RID: 133364927
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int Inf = 1e9;
int s,T,n,m,x,id[70][10],a[70];
int d[N],flow[M],cnt = 1;
int head[N],to[M],nxt[M];
void add(int u,int v,int w){
	to[++cnt] = v; nxt[cnt] = head[u];
	flow[cnt] = w; head[u] = cnt;
	to[++cnt] = u; nxt[cnt] = head[v];
	flow[cnt] = 0; head[v] = cnt;
}
bool bfs(){
	for(int i = 1;i <= T;i++) d[i] = 0;
	d[s] = 1; queue<int> q; q.push(s);
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(int i = head[now];i != 0;i = nxt[i]){
			if(flow[i] && !d[to[i]]){
				d[to[i]] = d[now] + 1; 
				q.push(to[i]);
			}
		}
	}
	return d[T] > 0;
}
int dfs(int u,int in){
	if(u == T) return in;
	int out = 0;
	for(int i = head[u];i != 0 && in != 0;i = nxt[i]){
		if(flow[i] && d[to[i]] == d[u] + 1){
			int x = dfs(to[i],min(in,flow[i]));
			in -= x; out += x; 
			flow[i] -= x; flow[i ^ 1] += x; 
		}
	}
	if(!out)d[u] = 0;
	return out;
}
int main(){
	cin >> n >> m; s = 501; T = 502;
	int pos = 0,sum = 0;
	for(int i = 1,x;i <= n;i++){
		cin >> x;
		for(int j = 0;j <= 5;j++) id[i][j] = ++pos;
		add(s,id[i][0],0);
		for(int j = 1;j < 5;j++){
			add(id[i][j],id[i][j + 1],x * j);
		}
		add(id[i][5],T,x * 5);
	}
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1;i <= m;i++){
		sum += a[i]; pos++; add(s,pos,a[i]);
		for(int j = 1,x;j <= n;j++){
			cin >> x; x--;
			add(pos,id[j][x],Inf);
		}
	}
	while(bfs()) sum -= dfs(s,Inf);
	cout << sum;
	return 0;
}