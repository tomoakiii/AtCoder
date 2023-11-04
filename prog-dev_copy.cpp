// LUOGU_RID: 128233230
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    int n,k,p,c[105],a[105][10],b[10];
    long long dp[10][10][10][10][10];
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> p ;
	for(int i=1;i<=n;i++){
		cin >> c[i] ;
		for(int j=1;j<=k;j++) cin >> a[i][j] ;
	}memset(dp,127,sizeof(dp));
	dp[0][0][0][0][0]=0;
	for(int i=1;i<=k;i++) b[i]=p;
	for(int i=1;i<=n;i++){
		for(int i1=b[1];~i1;i1--){
			for(int i2=b[2];~i2;i2--){
				for(int i3=b[3];~i3;i3--){
					for(int i4=b[4];~i4;i4--){
						for(int i5=b[5];~i5;i5--){
							int j1=max(0,i1-a[i][1]),j2=max(0,i2-a[i][2]),j3=max(0,i3-a[i][3]),j4=max(0,i4-a[i][4]),j5=max(0,i5-a[i][5]);
							dp[i1][i2][i3][i4][i5]=min(dp[i1][i2][i3][i4][i5],dp[j1][j2][j3][j4][j5]+c[i]);
						}
					}
				}
			}
		}
	}cout << (dp[b[1]][b[2]][b[3]][b[4]][b[5]]>1e11 ? -1 : dp[b[1]][b[2]][b[3]][b[4]][b[5]]) ;
	return 0;
}