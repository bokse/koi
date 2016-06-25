#include<stdio.h>

typedef long long ll;

const int MN = 1000 + 10;
const ll INF = 1e15;

ll A[MN][MN];
ll D[MN][MN];

ll min(ll a,ll b){
	if(a<b)return a;
	return b;
}

int main(){
	int N;
	ll sum;
	while(true){
		scanf("%d",&N);
		if(N==0)break;
		sum = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<=i;j++){
				scanf("%lld",&A[i][j]);
				sum += A[i][j];
			}
		}
		for(int j=0;j<N;j++){
			for(int i=N-2;i>=j;i--){
				A[i][j]+=A[i+1][j];
			}
		}
		D[0][0] = 0;
		for(int i = 1;i<=N;i++){
			D[0][i] = min(D[0][i-1],A[N-i][0]);
		}
		for(int j=1;j<N;j++){
			D[j][0] = D[j-1][1];
			for(int i=1;i<=N-j;i++){
				ll v = D[j-1][i+1] + A[N-i][j];
				D[j][i] = min(v,D[j][i-1]);
			}
		}
		printf("%lld\n",sum - D[N-1][1]);
	}
	return 0;
}
