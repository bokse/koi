#include<stdio.h>

const int MN = 100000;

int T,N;
int A[MN];
int indegree[MN];
int chk[MN];
int ans;

void dfs(int n){
	chk[n]=1;
	ans++;
	indegree[A[n]]--;
	if(indegree[A[n]]==0 && chk[A[n]]==0){
		dfs(A[n]);
	}
}

int main(){
	scanf("%d",&T);
	for(int tc=1;tc<=T;tc++){
		scanf("%d",&N);
		ans=0;
		for(int i=0;i<N;i++){
			indegree[i]=0;
			chk[i]=0;
		}
		for(int i=0;i<N;i++){
			scanf("%d",&A[i]),A[i]--;
			indegree[A[i]]++;
		}
		for(int i=0;i<N;i++)if(chk[i]==0 && indegree[i]==0){
			dfs(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
