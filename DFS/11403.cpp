#include<stdio.h>
#include<vector>
using namespace std;

const int MN = 100;

int N;
int A[MN][MN];
int chk[MN][MN];
int flag[MN];
void dfs(int st, int n){
	chk[st][n]=1;
	if(st==n && flag[n]==0){
		flag[n]=1;
		chk[st][n]=0;
	}
	for(int i=0;i<N;i++)if(A[n][i]){
		if(chk[st][i]==0){
			dfs(st,i);
		}
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		}
	}
	for(int i=0;i<N;i++){
		dfs(i,i);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",chk[i][j]);
		}
		printf("\n");
	}
	return 0;
}
