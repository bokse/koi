#include<stdio.h>

const int MN = 1500 + 5;

int N;
int A[MN][MN];
int D[MN][MN];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		scanf("%d",&A[i][j]);
	}
	D[1][0]=A[1][0];
	for(int i=2;i<N;i++){
		for(int j=0;j<i-1;j++){
			D[i][j]=D[i-1][j]+A[i][i-1];
		}
		D[i][i-1] = 100000000;
		for(int j=0;j<i-1;j++){
			if(D[i][i-1] > D[i-1][j]+A[i][j]){
				D[i][i-1] = D[i-1][j]+A[i][j];
			}
		}
	}
	int ans = D[N-1][0];
	for(int i=1;i<N-1;i++){
		if(ans>D[N-1][i]){
			ans=D[N-1][i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
