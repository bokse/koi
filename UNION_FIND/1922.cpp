#include<stdio.h>
#include<algorithm>
using namespace std;

const int MN = 1000 + 5;
const int MM = 100000 + 5;

struct EDGE{
	int a,b,c;
	bool operator <(EDGE A)const{
		return c<A.c;
	}
}edges[MM];

int N, M;
int p[MN];

int par(int n){
	if(p[n]==n)return n;
	return p[n]=par(p[n]);
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].c);
		edges[i].a--,edges[i].b--;
	}
	sort(edges,edges+M);
	for(int i=0;i<N;i++)p[i]=i;

	int ans=0;
	for(int i=0;i<M;i++){
		int p1 = par(edges[i].a);
		int p2 = par(edges[i].b);
		if(p1==p2)continue;
		p[p1]=p2;
		ans+=edges[i].c;
	}
	printf("%d\n",ans);
	return 0;
}
