#include<stdio.h>
#include<algorithm>
using namespace std;

const int MN = 1000000 + 10;
int p[MN],sz[MN];
int N, M;

int par(int n){
	if(p[n]==n)return n;
	return p[n]=par(p[n]);
}
void merge(int a,int b){
	a=par(a), b=par(b);
	if(a==b)return;
	if(sz[a]>sz[b]) swap(a,b);
	p[a]=b;
	sz[b]+=sz[a];
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<=N;i++)p[i]=i, sz[i]=1;
	for(int q=0;q<M;q++){
		int type, a, b;
		scanf("%d%d%d",&type,&a,&b);
		if(type==0){
			merge(a,b);
		}
		else{
			a=par(a), b=par(b);
			if(a==b) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
