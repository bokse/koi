#include<stdio.h>
#include<algorithm>
using namespace std;

const int MN = 100000 + 5;
const int MM = 300000 + 5;

struct PLANET{
	int x, y, z, index;
}planets[MN];
bool cmpX(PLANET a,PLANET b){	return a.x<b.x;	}
bool cmpY(PLANET a,PLANET b){	return a.y<b.y;	}
bool cmpZ(PLANET a,PLANET b){	return a.z<b.z;	}

int cost(int i,int j){
	return min(abs(planets[i].x-planets[j].x),
			min(abs(planets[i].y-planets[j].y),
				abs(planets[i].z-planets[j].z)));
}

struct EDGE{
	int a,b,c;
}edges[MM];
bool cmpC(EDGE a,EDGE b){	return a.c<b.c;	}

int N,M;
int p[MN];

int par(int n){
	if(p[n]==n)return n;
	return p[n]=par(p[n]);
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&planets[i].x,&planets[i].y,&planets[i].z);
		planets[i].index = i;
	}
	sort(planets,planets+N,cmpX);
	for(int i=0;i<N-1;i++){
		edges[M].a = planets[i].index;
		edges[M].b = planets[i+1].index;
		edges[M].c = cost(i,i+1);
		M++;
	}
	sort(planets,planets+N,cmpY);
	for(int i=0;i<N-1;i++){
		edges[M].a = planets[i].index;
		edges[M].b = planets[i+1].index;
		edges[M].c = cost(i,i+1);
		M++;
	}
	sort(planets,planets+N,cmpZ);
	for(int i=0;i<N-1;i++){
		edges[M].a = planets[i].index;
		edges[M].b = planets[i+1].index;
		edges[M].c = cost(i,i+1);
		M++;
	}
	sort(edges,edges+M,cmpC);
	for(int i=0;i<N;i++)p[i]=i;
	long long ans=0;
	for(int i=0;i<M;i++){
		int p1 = par(edges[i].a);
		int p2 = par(edges[i].b);
		if(p1==p2)continue;
		p[p1]=p2;
		ans+=edges[i].c;
	}
	printf("%lld\n",ans);
	return 0;
}

