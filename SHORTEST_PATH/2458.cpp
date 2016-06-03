#include<stdio.h>

const int MN = 500;

int less[MN][MN];

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);--a,--b;
		less[a][b]=1;
	}
	for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		if(less[i][k]&&less[k][j]){
			less[i][j]=1;
		}
	}
	int ans=0;
	for(int i=0;i<N;i++){
		bool flag=true;
		for(int j=0;j<N;j++)if(i!=j){
			if(!less[i][j] && !less[j][i]){
				flag=false;
			}
		}
		if(flag) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
