#include<stdio.h>
typedef long long ll;

int N,K;

int min(int a,int b){
	if(a<b)return a;
	return b;
}

ll f(ll m){
	ll sum=0;
	for(int i=1;i<=N;i++){
		sum+=min(N,(m/i));
	}
	return sum;
}

ll bsearch(){
	ll ans=-1;
	ll l=0,r=(ll)N*N,m;
	while(l<=r){
		m=(l+r)/2;
		if(f(m)>=K){
			ans=m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return ans;
}

int main(){
	scanf("%d%d",&N,&K);
	printf("%lld\n",bsearch());
	return 0;
}
