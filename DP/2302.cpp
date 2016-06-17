#include<stdio.h>

int D[50];

int main(){
	D[0] = D[1] = 1;
	for(int i=2;i<50;i++){
		D[i] = D[i-1] + D[i-2];
	}
	int N, M;
	scanf("%d%d",&N,&M);
	int prev = 0;
	int ans = 1;
	for(int i=0;i<M;i++){
		int a;
		scanf("%d",&a);
		ans *= D[a-prev-1];
		prev = a;
	}
	ans *= D[N-prev];
	printf("%d\n",ans);
	return 0;
}
