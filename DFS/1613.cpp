#include<stdio.h>
#include<vector>

using namespace std;

const int MN = 400 + 1;

int N,M,Q;
int chk[MN][MN];
vector<int> E[MN];

void dfs(int st, int n){
	chk[st][n]=1;
	for(int i=0;i<E[n].size();i++){
		if(!chk[st][E[n][i]]){
			dfs(st,E[n][i]);
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b),--a,--b;
		E[a].push_back(b);
	}
	for(int i=0;i<N;i++){
		dfs(i,i);
	}
	scanf("%d",&Q);
	for(int q=0;q<Q;q++){
		int a,b;
		scanf("%d%d",&a,&b),--a,--b;
		if(chk[a][b]){
			printf("-1\n");
		}
		else if(chk[b][a]){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
