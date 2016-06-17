#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

const int MN = 1000;
const int INF = 1000000000;

int N, M;
int A[MN], B[MN];
int D[MN][MN];

int DP(int N,int M,int *A,int *B){
	for(int i=0;i<N;i++){
		for(int j=i;j<M;j++){
			int v1 = abs(A[i] - B[j]);
			if(i>=1 && j>=1) v1 += D[i-1][j-1];

			int v2;
			if(i==j)v2=INF;
			else v2=D[i][j-1];

			D[i][j]=min(v1,v2);
		}
	}
	return D[N-1][M-1];
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&A[i]);
	for(int i=0;i<M;i++) scanf("%d",&B[i]);
	sort(A,A+N); sort(B,B+M);
	int ans;
	if(N<M) ans = DP(N,M,A,B);
	else ans = DP(M,N,B,A);

	printf("%d\n",ans);
	return 0;
}
