#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
using std::max;
int tr[N<<2],tag[N<<2];

void Down(int x){
  tr[x<<1]+=tag[x];
  tr[x<<1|1]+=tag[x];
  tag[x<<1]+=tag[x];
  tag[x<<1|1]+=tag[x];
  tag[x]=0;
}

void Update(int l,int r,int s,int t,int x,int k){
  if(s<=l&&r<=t){
    tr[k]+=x;
    tag[k]+=x;
    return;
  }
  if(tag[k])Down(k);
  int mid=(l+r)>>1;
  if(s<=mid)Update(l,mid,s,t,x,k<<1);
  if(t>mid)Update(mid+1,r,s,t,x,k<<1|1);
  tr[k]=max(tr[k<<1],tr[k<<1|1]);
}

struct Seg{
  int x,t;
}s[N];

bool operator<(Seg a,Seg b){
  return a.t<b.t;
}

int main(){
  int n,d,w;
  scanf("%d%d%d",&n,&d,&w);
  int max_t=0,max_x=0;
  for(int i=1;i<=n;++i){
    scanf("%d%d",&s[i].t,&s[i].x);
    max_t=max(max_t,s[i].t);
    max_x=max(max_x,s[i].x);
  }
  std::sort(s+1,s+1+n);
  int j=0,k=1,ans=0;
  for(int t=1;t<=max_t;++t){
    while(s[j+1].t<t+d&&j<n){
      Update(1,max_x,max(1,s[j+1].x-w+1),s[j+1].x,1,1);
      ++j;
    }
    while(s[k].t<t&&k<=j){
      Update(1,max_x,max(1,s[k].x-w+1),s[k].x,-1,1);
      ++k;
    }
    ans=max(ans,tr[1]);
  }
  printf("%d",ans);
}
