#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MN = 100000 + 5;

int N,M;
int p[MN],sz[MN];

struct EDGE{
	int a,b,c;
	bool operator <(EDGE A)const{
		return c>A.c;
	}
}edges[MN];

ll nC2(int n){
	return (ll)n*(n-1)/2;
}
int par(int n){
	if(p[n]==n)return n;
	return p[n]=par(p[n]);
}
void merge(int a,int b,ll &count){
	a=par(a), b=par(b);
	if(a==b)return;
	count -= nC2(sz[a]);
	count -= nC2(sz[b]);
	count += nC2(sz[a]+sz[b]);
	p[a]=b;
	sz[b]+=sz[a];
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].c);
		edges[i].a--,edges[i].b--;
	}
	sort(edges,edges+M);
	for(int i=0;i<N;i++){
		p[i]=i;
		sz[i]=1;
	}
	ll cnt = 0, ans = 0;
	for(int i=0;i<M;i++){
		merge(edges[i].a,edges[i].b,cnt);
		ans += cnt*edges[i].c;
	}
	ans = ans%1000000000;
	printf("%lld\n",ans);
	return 0;
}
