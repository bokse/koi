#include<stdio.h>
typedef long long ll;
using namespace std;

const int MN = 100000;

int N, M;
int T[MN];

int main(){
	scanf("%d%d",&N,&M);
	int mint = 1e9;
	for(int i=0;i<N;i++){
		scanf("%d",&T[i]);
		if(mint > T[i]) mint = T[i];
	}
	ll l=0,r=(ll)mint * M,m;
	ll ans=-1;
	while(l<=r){
		m=(l+r)/2;
		ll sum=0;
		for(int i=0;i<N;i++){
			sum += (m/T[i]);
		}
		if(sum>=M){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	printf("%lld\n",ans);
	return 0;
}
